#include "imgproc.h"


template<class T> void blur(const _Matrix<T>& src, _Matrix<T>& dst, Size ksize, int borderType)
{
    _Matrix<T> kernel = _Matrix<T>::ones(ksize);
    dst = conv(src, kernel);
}

template<class T> void boxFilter(const _Matrix<T>& src, _Matrix<T>& dst, int ddepth, Size ksize, bool normalize, int borderType)
{
    int row = mat.GetRow();
    int col = mat.GetCol();

    int krow = ksize.GetHeight();
    int kcol = ksize.GetWidth();

    if(krow != kcol || krow % 2 ==0)
    {
        //Error
    }

    T* buff = new T[col];
    T* sum = new T[(col-kcol)*(row-krow)];

    memset(buff, 0, col*sizeof(T));
    memset(sum, 0, (col-kcol)*(row-krow)*sizeof(T));

    for(int i=0;i<col;i++)
        for(int j=0;j<krow;j++)
        {
            buff[i] += mat[j][i];
        }

    for(int k=0;k<row-krow;k++)
    {
        for(int i=0;i<kcol;i++)
        {
            sum[k*(col-kcol)] += buff[i];
        }

        for(int j=1;j<col-kcol;j++)
        {
            sum[k*(col-kcol)+j] = sum[k*(col-kcol)+(j-1)] - mat[k][j-1] + buff[j+kcol-1];
        }


        for(int m=0;m<col;m++)
        {
            buff[m] = buff[m] - mat[k][m] + mat[k+krow][m];
        }
    }

    for(int y=0;y<row;y++)
        for(int x=0;x<col;x++)
        {
            if(y>krow/2 && y<row - krow/2 && x>kcol/2 && x<col - kcol/2)
            {
                if(normalize)
                    dst[y][x] = sum[(y-krow/2)*(col-kcol)+(x-kcol/2)]/(kcol*krow);
                else
                    dst[y][x] = sum[(y-krow/2)*(col-kcol)+(x-kcol/2)];
            }
            else
            {
                dst[y][x] = 0;
            }
        }

    delete[] buff;
    delete[] sum;
}

template<class T> void bilateralFilter(const _Matrix<T>& src, _Matrix<T>& dst, int d, double sigmaColor, double sigmaSpace, int borderType);

template<class T> void GaussianBlur(const _Matrix<T>& src, _Matrix<T>& dst, Size ksize, double sigmaX, double sigmaY, int borderType)
{//ksize.width and ksize.height can differ
    assert(ksize.width>0 && ksize.width%2==1);
    assert(ksize.height>0 && ksize.height%2==1);

    if(sigmaX == 0 && sigmaY == 0)
    {
        sigmaX = 0.3*((ksize.GetWidth()-1)*0.5 - 1) + 0.8;
        sigmaY = 0.3*((ksize.GetHeight()-1)*0.5 - 1) + 0.8;
    }
    else if(sigmaY == 0)
        sigmaY = sigmaX;

    Matrix kernel = getGaussianKernel(ksize, sigmaX, sigmaY);//could do in one dimension twice for
    dst = conv(src, kernel, false);
}

template<class T> Matrix getGaussianKernel(Size ksize, double sigmaX, double sigmaY)
{
    Matrix kernel(ksize);

    int y = ksize.GetHeight();
    int x = ksize.GetWidth();

    double alpha = 0;

    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++)
        {
            kernel[i][j] = exp(-0.5*pow(i-(y-1)/2, 2)/(sigmaX*sigmaX) - 0.5*pow(j-(x-1)/2, 2)/(sigmaY*sigmaY));
            alpha += kernel[i][j];
        }

    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++)
        {
            kernel[i][j] /= alpha;  //normalize
        }

    return kernel;
}

template<class T> void medianBlur(const _Matrix<T>& src, _Matrix<T>& dst, int ksize)
{

}

template<class T> void morphologyEx(const _Matrix<T>& src, _Matrix<T>& dst, int op, const Matrix& kernel)
{
    switch(op)
    {
    case MORPH_ERODE:
        erode(src, dst, kernel);
        break;
    case MORPH_DILATE:
        dilate(src, dst, kernel);
        break;
    case MORPH_OPEN:
        erode(src, buf2, kernel);
        dilate(buf2, dst, kernel);
        break;
    case CV_MOP_CLOSE:
        dilate(src, buf2, kernel);
        erode(buf2, dst, kernel);
        break;
    case CV_MOP_GRADIENT:
        erode(src, buf2, kernel);
        dilate(src, dst, kernel);
        subtract(dst, buf2, dst, GpuMat(), -1, stream);
        break;
    case CV_MOP_TOPHAT:
        erode(src, dst, kernel);
        dilate(dst, buf2, kernel);
        subtract(src, buf2, dst, GpuMat(), -1, stream);
        break;
    case CV_MOP_BLACKHAT:
        dilate(src, dst, kernel);
        erode(dst, buf2, kernel);
        subtract(buf2, src, dst, GpuMat(), -1, stream);
        break;
    default:
        //Error
    }
}

template<class T> void dilate(const _Matrix<T>& src, _Matrix<T>& dst, const Mat& kernel)
{
    int row = src.GetRow();
    int col = src.GetCol();
    int channel = src.GetChannel();

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            for(int k=0;k<channel;k++)
            {
                T max_val;
                bool first = true;

                for(int m=0;m<=kernel.GetRow();m++)
                    for(int n=0;n<=kernel.GetCol();n++)
                    {
                        int y = i-(kernel.GetRow()/2)+m;
                        int x = j-(kernel.GetCol()/2)+n;

                        if(x>=0 && y>=0 && x<=col && y<=row)
                        {
                            T val = src[y][x*channel+k];
                            if(first)
                            {
                                max_val = val;
                                first = false;
                            }
                            else if(max_val < val)
                                max_val = val;
                        }
                    }
                dst[i][j*channel+k] = max_val;
            }
}

template<class T> void erode(const _Matrix<T>& src, _Matrix<T>& dst, const Mat& kernel)
{
    int row = src.GetRow();
    int col = src.GetCol();
    int channel = src.GetChannel();

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            for(int k=0;k<channel;k++)
            {
                T min_val;
                bool first = true;

                for(int m=0;m<=kernel.GetRow();m++)
                    for(int n=0;n<=kernel.GetCol();n++)
                    {
                        int y = i-(kernel.GetRow()/2)+m;
                        int x = j-(kernel.GetCol()/2)+n;

                        if(x>=0 && y>=0 && x<=col && y<=row)
                        {
                            T val = src[y][x*channel+k];
                            if(first)
                            {
                                min_val = val;
                                first = false;
                            }
                            else if(min_val > val)
                                min_val = val;
                        }
                    }
                dst[i][j*channel+k] = min_val;
            }
}

template<class T> void cvtColor(const _Matrix<T>& src, _Matrix<T>& dst, int code)
{
    int row = src.GetRow();
    int col = src.GetCol();
    int cha = src.GetChannel();

    switch (code)
    {
    case RGB2GRAY:
        if(!(dst.GetSize() == src.GetSize() && dst.channel == 1))
            dst.recreate(src.GetRow(), src.GetCol(), 1);

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                dst[i][j] = 0.299*src[i][j*cha] + 0.587*src[i][j*cha+1] + 0.114*src[i][j*cha+2];
            }
        break;

    case BGR2RGB:
        if(!(dst.GetSize() == src.GetSize() && dst.channel == 3))
                dst.recreate(src.GetRow(), src.GetCol(), 3);

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                dst[i][j*cha] = src[i][j*cha+2];
                dst[i][j*cha+1] = src[i][j*cha+1];
                dst[i][j*cha+2] = src[i][j*cha];
            }
        break;

    default:
        break;
    }

}

template<class T> int Otsu(Matrix8u mat)
{
    if(mat.isempty() || mat.GetChannel() != 1)
    {
        //error
    }

    double* pix = new double[256];
    double* avg_pix = new double[256];
    memset(pix, 0, sizeof(pix));
    memset(avg_pix, 0, sizeof(avg_pix));

    int area = mat.GetSize().area();

    for(int i=0;i<mat.GetRow();i++)
        for(int j=0;j<mat.GetCol();j++)
        {
            pix[mat[i][j]]++;
        }

    pix[0] /= area;
    avg_pix[0] = 0;

    int threshold = 0;
    double max_val = 0;

    for(int j=1;j<256;j++)
    {
        pix[j] /= area;
        pix[j] += pix[j-1];
        avg_pix[j] = avg_pix[j-1] + j*pix[j];
    }

    double pt = avg_pix[255];

    for(int k=0;k<256;k++)
    {
        double P1 = pix[k];
        double p2 = 1 - pix[k];

        if(fabs(p1) > 0.001 && fabs(p2) > 0.001)
        {
            double m1 = avg_pix[k];
            double m2 = (pt - p1*m1)/p2;
            double val = (double)(p1 * p2 * pow((p1-p2),2));

            if(val > max_val)
            {
                max_val = val;
                threshold = k;
            }
        }
    }
    return threshold;

    delete[] pix;
    delete[] avg_pix;
}

template<class T> void Sobel(const Matrix8u& src, Matrix<T>& dst, int dx, int dy, int ksize, bool thresholding, bool get_dir, Matrix8u& dir)
{
    int cha = src.GetChannel();

    if(dst.GetSize() != src.GetSize())
        dst.recreate(src.GetRow(), src.GetCol(), cha);

    if(get_dir && dir.GetSize() != src.GetSize())
        dir.recreate(src.GetRow(), src.GetCol(), cha);

    Matrix sobel_x = (ksize, ksize);
    Matrix sobel_y = (ksize, ksize);

    switch (ksize) //ksize to be bigger, result to be blurred
    {
    case 1:

    case 3:
        sobel_x = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
        sobel_y = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
        break;
    case 5:

    case 7:

    default:
        //error
        return;
    }

    int threshold = Otsu(src);

    for(int i=0;i<dst.GetRow();i++)
        for(int j=0;j<dst.GetCol();j++)
            for(int k=0;k<dst.GetChannel();k++)
            {
                double grad_x = 0;
                double grad_y = 0;

                double temp_x = 0;
                double temp_y = 0;

                for(int m=0;m<ksize;m++)
                    for(int n=0;n<ksize;n++)
                    {
                        int y = i-ksize/2 + m;
                        int x = j-ksize/2 + n;

                        if(x>=0 && y>=0 && x<=dst.GetCol() && y<=dst.GetRow())
                        {
                            temp_x += src[y][x*cha+k] * sobel_x[m][n];
                            temp_y += src[y][x*cha+k] * sobel_y[m][n];
                        }
                    }

                    if(get_dir)
                    {
                        double theta = atan2(temp_y, temp_x)*RAD2ANG;

                        if ((theta>=0 && theta<45) || (theta<-135))
                            dir[i][j*cha+k] = 0;
                        else if ((theta>=45 && theta<90) || (theta>=-135 && theta<-90))
                            dir[i][j*cha+k] = 1;
                        else if ((theta>=90 && theta<135) || (theta>=-90 && theta<-45))
                            dir[i][j*cha+k] = 2;
                        else
                            dir[i][j*cha+k] = 3;
                    }

                    grad_x = abs(temp_x);
                    grad_y = abs(temp_y);

                    if(thresholding) //Canny does not implement thresholding right here
                    {
                        double grad_x = ((grad_x > threshold) ? 255 : 0);
                        double grad_y = ((grad_y > threshold) ? 255 : 0);
                    }

                    dst[i][j*cha+k] = (dx/(dx+dy))*grad_x + (dy/(dx+dy))*grad_y; //simplified for efficiency

                }
}


template<class T> void Scharr(const Matrix8u& src, Matrix8u& dst, Matrix8u& grad, int dx, int dy, int ksize)
{

}

template<class T> void Canny(const Matrix8u& image, const Matrix8u& edges, double threshold1, double threshold2, bool L2gradient=false)
{
    Matrix8u grad_x;
    Matrix8u grad_y;
    Matrix grad;
    Matrix8u dir;

    //Gaussian Blur
    GaussianBlur(image, image, (5, 5));  //5 * 5 trade-off, too large->less accuracy, too small->suffer from noise

    //Calculate the gradient values and directions
    Sobel(image, grad_x, 1, 0, 3, false);
    Sobel(image, grad_y, 0, 1, 3, false);
    Sobel(image, grad, 1, 1, 3, false, true, dir);

    //Select threshold
    if(threshold1 == 0 && threshold2 == 0)
    {

    }

    //Non-maximum Suppression (using Linear interpolation)

    for(int i=0;i<grad.GetRow();i++)
        for(int j=0;j<grad.GetCol();j++)
        {
            double grad_p1, grad_p2;

            //Linear interpolation
            if(dir[i][j] == 0)
            {
                double d = grad_y[i][j] / grad_x[i][j];
                grad_p1 = (1-d)*grad[i][j+1] + d*grad[i-1][j+1];
                grad_p2 = (1-d)*grad[i][j-1] + d*grad[i+1][j-1];
            }
            else if(dir[i][j] == 1)
            {
                double d = grad_x[i][j] / grad_y[i][j];
                grad_p1 = (1-d)*grad[i-1][j] + d*grad[i-1][j+1];
                grad_p2 = (1-d)*grad[i+1][j] + d*grad[i+1][j-1];
            }
            else if(dir[i][j] == 2)
            {
                double d = grad_x[i][j] / grad_y[i][j];
                grad_p1 = (1-d)*grad[i-1][j] + d*grad[i-1][j-1];
                grad_p2 = (1-d)*grad[i+1][j] + d*grad[i+1][j+1];
            }
            else if(dir[i][j] == 3)
            {
                double d = grad_y[i][j] / grad_x[i][j];
                grad_p1 = (1-d)*grad[i][j-1] + d*grad[i-1][j-1];
                grad_p2 = (1-d)*grad[i][j+1] + d*grad[i+1][j+1];
            }

            //NMS & Double-Threshold
            if(grad[i][j]>=grad_p1 && grad[i][j]>=grad_p2)
            {
                if(grad[i][j]>threshold2)
                {
                    grad[i][j] = 255;
                }
                else if(grad[i][j]>threshold1)
                {
                    grad[i][j] = threshold2;
                }
                else
                {
                    grad[i][j] = 0;
                }
            }
            else
                grad[i][j] = 0;
        }

        //Retain those pixels one of whose nearby pixels belongs to a strong edge
        for(int i=0;i<grad.GetRow();i++)
            for(int j=0;j<grad.GetCol();j++)
            {
                if(grad[i][j] == threshold2)
                {
                    grad[i][j] = 0;
                    for(int m=-1;m<=1;m++)
                        for(int n=-1;n<=1;n++)
                        {
                            if((m==0 && n==0) || i+m<0 || i+m>grad.GetRow() || j+n<0 || j+n>grad.GetCol())
                                continue;
                            if(grad[i+m][j+n]==255)
                            {
                                grad[i][j] = 255;
                                break;
                            }
                        }
                }

            }
}

template<class T> void pyrUp(const Matrix8u& src, Matrix8u& dst, const Size& dstsize)
{
    if(dstsize.isempty())
    {
        dstsize.SetHeight(src.GetRow()*2);
        dstsize.SetWidth(src.GetCol()*2);
    }
    assert(abs(dstsize.GetWidth()-src.GetCol()*2)<=(dstsize.GetWidth()%2) && abs(dstsize.GetHeight()-src.GetRow()*2)<=(dstsize.GetHeight()%2));

    Matrix8u tmp = Matrix8u::zeros(dstsize.GetHeight(), dstsize.GetWidth());
    Matrix8u dst;

    for(int i=0;i<src.GetRow();i++)
        for(int j=0;j<src.GetCol();j++)
        {
            tmp[i*2][j*2] = src[i][j];
        }

    Matrix kernel = 4 * getGaussianKernel(Size(5, 5), 1.1, 1.1);  //multiplied by 4 to scale the image intensities to the proper values

    dst = conv(tmp, kernel, false);
}


template<class T> void pyrDown(const Matrix8u& src, Matrix8u& dst, const Size& dstsize)
{
    if(dstsize.isempty())
    {
        dstsize.SetHeight(src.GetRow()/2);
        dstsize.SetWidth(src.GetCol()/2);
    }
    assert(abs(dstsize.GetWidth()*2-src.GetCol())<=2 && abs(dstsize.GetHeight()*2-src.GetRow())<=2);

    dst.recreate(dstsize.GetHeight(), dstsize.GetWidth(), 1);

    Matrix8u tmp(src.GetRow(), src.GetCol());

    GaussianBlur(src, tmp, Size(5, 5), 0);

    for(int i=0;i<dstsize.GetHeight();i++)
        for(int j=0;j<dstsize.GetWidth();j++)
        {
            dst[i][j] = tmp[i*2][j*2];
        }
}

