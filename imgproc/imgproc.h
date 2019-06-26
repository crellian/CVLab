#include "type.h"

#define RAD2ANG			((double)(57.296))

template<class T> void blur(const _Matrix<T>& src, _Matrix<T>& dst, Size ksize, int borderType=BORDER_DEFAULT);
template<class T> void boxFilter(const _Matrix<T>& src, _Matrix<T>& dst, int ddepth, Size ksize, bool normalize=true, int borderType=BORDER_DEFAULT );
template<class T> void bilateralFilter(const _Matrix<T>& src, _Matrix<T>& dst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT );
template<class T> void GaussianBlur(const _Matrix<T>& src, _Matrix<T>& dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT);
template<class T> void medianBlur(const _Matrix<T>& src, _Matrix<T>& dst, int ksize);
template<class T> void morphologyEx(const _Matrix<T>& src, _Matrix<T>& dst, int op, const Matrix& kernel);

template<class T> Matrix getGaussianKernel(Size ksize, double sigma, double sigmaY);
template<class T> void dilate(const _Matrix<T>& src, _Matrix<T>& dst, const Mat& kernel);
template<class T> void erode(const _Matrix<T>& src, _Matrix<T>& dst, const Mat& kernel);
template<class T> void cvtColor(const _Matrix<T>& src, _Matrix<T>& dst, int code);
template<class T> int Otsu(Matrix8u mat);
template<class T> void Sobel(const Matrix8u& src, Matrix8u& dst, int dx = 1, int dy = 1, int ksize = 3, bool thresholding=true, bool get_dir = false, Matrix8u& dir = Matrix8u());
template<class T> void Scharr(const Matrix8u& src, Matrix8u& dst, int dx = 1, int dy = 1, int ksize = 3);
template<class T> void Canny(const Matrix8u& image, const Matrix8u& edges, double threshold1 = 0, double threshold2 = 0, bool L2gradient=false); // default using Otsu for selecting thresholds
template<class T> void pyrUp(const Matrix8u& src, Matrix8u& dst, const Size& dstsize=Size());
template<class T> void pyrDown(const Matrix8u& src, Matrix8u& dst, const Size& dstsize=Size());
