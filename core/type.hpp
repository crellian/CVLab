#ifndef MODULES_CORE_TYPE_HPP_
#define MODULES_CORE_TYPE_HPP_
#include <iostream>
#include <cstring>

// Type for vector data
// Type Vector is for int8_t
namespace CVlab
{

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T> _Vector<T>::_Vector() :len(0), data(NULL){}
template<class T> _Vector<T>::_Vector(int _len) :len(_len), data(new T[_len]) {memset(data, 0, _len * sizeof(T));}
template<class T> _Vector<T>::_Vector(int _len, T val) :len(_len), data(new T[_len]) {for(int i=0;i<_len;i++) data[i]=val;}
template<class T> _Vector<T>::_Vector(int _len, const T* _data) :len(_len), data(new T[_len]) {for(int i=0;i<_len;i++) data[i]=_data[i];}
template<class T> _Vector<T>::_Vector(const _Vector<T>& v) :len(v.len), data(v.data) {}

template<class T> _Vector<T>& _Vector<T>::operator = (std::initializer_list<T> ls)
{
    int id=0;
    for(const auto& item: ls)
        data[id++]=item;
    len = id;
    return (*this);
}

template<class T> _Vector<T>& _Vector<T>::operator = (const _Vector<T>& v)
{
    len = v.GetLen();
    data = new T[len];
    for(int id=0;id<v.len;id++)
        data[id]=v[id];
    return (*this);
}

template<class T> const T& _Vector<T>::operator[] (int idx) const {return *(data+idx);}
template<class T> T& _Vector<T>::operator[] (int idx) {return *(data+idx);}

template<class T> void _Vector<T>::SetLen(int _len) const
{
    T* _data=new T[_len];
    for(int i=0;i<len && i<_len;i++)
        _data[i] = data[i];
    delete [](data);
    data = _data;
    len=_len;
}

template<class T> int _Vector<T>::GetLen() const {return len;}

template<class T> _Vector<T>::~_Vector() {delete []data; data=NULL;}

template<class T> bool operator == (const _Vector<T>& v1, const _Vector<T>& v2)
{
    int len = v1.GetLen();
    if(len != v2.GetLen())
        return false;
    for(int i=0; i<len; i++)
        if(v1[i] != v2[i])
        return false;
    return true;
}

template<class T> bool operator != (const _Vector<T>& v1, const _Vector<T>& v2) {return !(v1 == v2);}

template<class T> std::ostream& operator << (std::ostream& os, const _Vector<T>& v)
{
    for(int i=0;i<v.GetLen();i++)
        os<<(int)v[i]<<" ";
    return os;
}


// Type for size data
template<class T> _Size<T>::_Size() :width(0), height(0) {}
template<class T> _Size<T>::_Size(T _width, T _height) :width(_width), height(_height) {}
template<class T> _Size<T>::_Size(const _Size<T>& s) :width(s.width), height(s.height) {}

template<class T> T _Size<T>::area() const {return width*height;}

template<class T> void _Size<T>::SetWidth(T val) {width=val;}
template<class T> void _Size<T>::SetHeight(T val) {height=val;}
template<class T> T _Size<T>::GetWidth() const {return width;}
template<class T> T _Size<T>::GetHeight() const {return height;}

template<class T> bool operator == (const _Size<T>& s1, const _Size<T>& s2) {return (s1.GetWidth() == s2.GetWidth()) && (s1.GetHeight() == s2.GetHeight());}
template<class T> bool operator != (const _Size<T>& s1, const _Size<T>& s2) {return (s1.GetWidth() != s2.GetWidth()) || (s1.GetHeight() != s2.GetHeight());}
template<class T> std::ostream& operator << (std::ostream& os, const _Size<T>& s) {return os << "(" << s.GetWidth() << "," << s.GetHeight() << ")";}

// Type for complex data
// Type Complex is for int8_t


// Type for 3d Point data
// Type Point3 is for int
template<class T> _Point3<T>::_Point3() :x(0),y(0),z(0) {};
template<class T> _Point3<T>::_Point3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {};
template<class T> _Point3<T>::_Point3(const _Point3<T>& p) :x(p.x), y(p.y), z(p.z){};

template<class T> T _Point3<T>::DotPdt(const _Point3<T>& p) const {return (x * p.GetX()) + (y * p.GetY()) + (z * p.GetZ());}
template<class T> _Point3<T> _Point3<T>::CrossPdt(const _Point3<T>& p) const {return {(y * p.GetZ() - z * p.GetY()), (z * p.GetX() - x * p.GetZ()), (x * p.GetY() - y * p.GetX())};}

template<class T> void _Point3<T>::SetX(T val) {x=val;}
template<class T> void _Point3<T>::SetY(T val) {y=val;}
template<class T> void _Point3<T>::SetZ(T val) {z=val;}
template<class T> T _Point3<T>::GetX() const {return x;}
template<class T> T _Point3<T>::GetY() const {return y;}
template<class T> T _Point3<T>::GetZ() const {return z;}

template<class T> _Point3<T> operator + (const _Point3<T>& p1, const _Point3<T>& p2) {return {p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY(), p1.GetZ() + p2.GetZ()};}
template<class T> bool operator == (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() == p2.GetX()) && (p1.GetY() == p2.GetY()) && (p1.GetZ() == p2.GetZ());}
template<class T> bool operator != (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() != p2.GetX()) || (p1.GetY() != p2.GetY()) || (p1.GetZ() != p2.GetZ());}
template<class T> bool operator <= (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() <= p2.GetX()) && (p1.GetY() <= p2.GetY()) && (p1.GetZ() <= p2.GetZ());}
template<class T> bool operator < (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() < p2.GetX()) && (p1.GetY() < p2.GetY()) && (p1.GetZ() < p2.GetZ());}
template<class T> bool operator >= (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() >= p2.GetX()) && (p1.GetY() >= p2.GetY()) && (p1.GetZ() >= p2.GetZ());}
template<class T> bool operator > (const _Point3<T>& p1, const _Point3<T>& p2) {return (p1.GetX() > p2.GetX()) && (p1.GetY() > p2.GetY()) && (p1.GetZ() > p2.GetZ());}
template<class T> std::ostream& operator << (std::ostream& os, const _Point3<T>& p) { return os << "(" << p.GetX() << "," << p.GetY() << "," << p.GetZ() << ")";}

// Type for 2d Point data
// Type Point is for int
template<class T> _Point<T>::_Point() :x(0),y(0) {};
template<class T> _Point<T>::_Point(T _x, T _y) :x(_x), y(_y) {};
template<class T> _Point<T>::_Point(const _Point<T>& p) :x(p.x), y(p.y) {};

template<class T> T _Point<T>::DotPdt(const _Point<T>& p) const {return (x * p.GetX()) + (y * p.GetY());}
template<class T> _Point3<T> _Point<T>::CrossPdt(const _Point<T>& p) const {return {0, 0, x * p.GetY() - y * p.GetX()};}

template<class T> void _Point<T>::SetX(T val) {x=val;}
template<class T> void _Point<T>::SetY(T val) {y=val;}
template<class T> T _Point<T>::GetX() const {return x;}
template<class T> T _Point<T>::GetY() const {return y;}

template<class T> _Point<T>::~_Point() {}

template<class T> _Point<T> operator + (const _Point<T>& p1, const _Point<T>& p2) {return {p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY()};}
template<class T> bool operator == (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() == p2.GetX()) && (p1.GetY() == p2.GetY());}
template<class T> bool operator != (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() != p2.GetX()) || (p1.GetY() != p2.GetY());}
template<class T> bool operator <= (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() <= p2.GetX()) && (p1.GetY() <= p2.GetY());}
template<class T> bool operator < (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() < p2.GetX()) && (p1.GetY() < p2.GetY());}
template<class T> bool operator >= (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() >= p2.GetX()) && (p1.GetY() >= p2.GetY());}
template<class T> bool operator > (const _Point<T>& p1, const _Point<T>& p2) {return (p1.GetX() > p2.GetX()) && (p1.GetY() > p2.GetY());}
template<class T> std::ostream& operator << (std::ostream& os, const _Point<T>& p) {return os << "(" << p.GetX() << "," << p.GetY() << ")";}

// Type for Rectangle
// Type Rect is for int
template<class T> _Rect<T>::_Rect() :width(0), height(0), x(0), y(0) {}
template<class T> _Rect<T>::_Rect(T _width, T _height, T _x, T _y) :width(_width), height(_height), x(_x), y(_y) {}
template<class T> _Rect<T>::_Rect(const _Rect<T>& r) :width(r.GetWidth()), height(r.GetHeight()), x(r.GetX()), y(r.GetY()) {}
template<class T> _Rect<T>::_Rect(const _Size<T>& s, const _Point<T>& p) :width(s.GetWidth()), height(s.GetHeight()), x(p.GetX()), y(p.GetY()) {}
template<class T> _Rect<T>::_Rect(const _Point<T>& p1, const _Point<T>& p2) :width(p1.GetX()), height(p1.GetY()), x(p2.GetX()), y(p2.GetY()) {}

template<class T> _Point<T> _Rect<T>::GetTL() const {return {x, y};}
template<class T> _Point<T> _Rect<T>::GetBR() const {return {x+width, y+height};}
template<class T> _Size<T> _Rect<T>::GetSize() const {return {width, height};}
template<class T> bool _Rect<T>::contain(const _Point<T>& p) const {return (x < p.GetX()) && (p.GetX() < (x + width)) && (y < p.GetY()) && (p.GetY() < (y + height));}

template<class T> void _Rect<T>::SetWidth(T val) {width=val;}
template<class T> void _Rect<T>::SetHeight(T val) {height=val;}
template<class T> T _Rect<T>::GetWidth() const {return width;}
template<class T> T _Rect<T>::GetHeight() const {return height;}
template<class T> void _Rect<T>::SetX(T val) {x=val;}
template<class T> void _Rect<T>::SetY(T val) {y=val;}
template<class T> T _Rect<T>::GetX() const {return x;}
template<class T> T _Rect<T>::GetY() const {return y;}


// Type for Scalar
// Type Scalar is for double

template<class T> _Scalar<T>::_Scalar() {v[0]=0; v[1]=0; v[2]=0; v[3]=0;}
template<class T> _Scalar<T>::_Scalar(T v1, T v2, T v3, T v4) {v[0]=v1; v[1]=v2; v[2]=v3; v[3]=v4;}
template<class T> _Scalar<T>::_Scalar(const _Scalar<T>& s) {v[0]=s.v[0]; v[1]=s.v[1]; v[2]=s.v[2]; v[3]=s.v[3];}

template<class T> const T& _Scalar<T>::operator[] (int idx) const {return v[idx];}
template<class T> T& _Scalar<T>::operator[] (int idx) {return v[idx];}

template<class T> void _Scalar<T>::init(T val) {v[0] = v[1] = v[2] = v[3] = val;}
template<class T> _Scalar<T> _Scalar<T>::conj() const {return {v[0], -v[1], -v[2], -v[3]};}
template<class T> bool _Scalar<T>::isReal() const {return ((v[1] == 0) && (v[2] == 0) && (v[3] == 0));}

template<class T> bool operator == (const _Scalar<T>& s1, const _Scalar<T>& s2) {return !(s1 != s2);}
template<class T> bool operator != (const _Scalar<T>& s1, const _Scalar<T>& s2) {for(int i=0; i<4; i++) if(s1[i] != s2[i]) return true; return false;}
template<class T> _Scalar<T>& operator += (_Scalar<T>& s1, const _Scalar<T>& s2) {for(int i=0; i<4; i++) s1[i] += s2[i]; return s1;}
template<class T> _Scalar<T>& operator -= (_Scalar<T>& s1, const _Scalar<T>& s2) {for(int i=0; i<4; i++) s1[i] -= s2[i]; return s1;}
template<class T, class _T> _Scalar<T>& operator *= (_Scalar<T>& s, _T val) {for(int i=0; i<4; i++) s[i] *= val; return s;}
template<class T> _Scalar<T> operator + (const _Scalar<T>& s1, const _Scalar<T>& s2) {return {s1[0] + s2[0], s1[1] + s2[1], s1[2] + s2[2], s1[3] + s2[3]};}
template<class T> _Scalar<T> operator - (const _Scalar<T>& s1, const _Scalar<T>& s2) {return {s1[0] - s2[0], s1[1] - s2[1], s1[2] - s2[2], s1[3] - s2[3]};}
template<class T, class _T> _Scalar<T> operator * (const _Scalar<T>& s, _T val) {return {s[0] * val, s[1] * val, s[2] * val, s[3] * val};}
template<class T, class _T> _Scalar<T> operator * (_T val, const _Scalar<T>& s) {return {s[0] * val, s[1] * val, s[2] * val, s[3] * val};}
template<class T> std::ostream& operator << (std::ostream& os, const _Scalar<T>& s) {return os<<"["<<s[0]<<", "<<s[1]<<", "<<s[2]<<", "<<s[3]<<"]";}

// Type for Matrix
template<class T> _Matrix<T>::_Matrix() :channel(0), row(0), col(0), data_p(NULL){}
template<class T> _Matrix<T>::_Matrix(int _row, int _col, int _channel) :channel(_channel), row(_row), col(_col), data_p(new Data(_row, _col, _channel)){}
template<class T> _Matrix<T>::_Matrix(const _Size<int> s, int _channel) :channel(_channel), row(s.GetHeight()), col(s.GetWidth()), data_p(new Data(s.GetHeight(), s.GetWidth(), _channel)){}
template<class T> _Matrix<T>::_Matrix(const _Matrix<T>& m) :channel(m.channel), row(m.row), col(m.col), data_p(m.data_p){++(data_p->refCount);}

template<class T> _Matrix<T>& _Matrix<T>::operator = (const _Matrix<T>& m)
{
    if(data_p == m.data_p)
        return (*this);

    (*this).recreate(m.GetRow(),m.GetCol(),m.GetChannel());

    if(data_p && --data_p->refCount == 0)
        delete data_p;

    data_p = m.data_p;
    ++data_p->refCount;
    return (*this);
}

template<class T> _Matrix<T>& _Matrix<T>::operator = (std::initializer_list<T> ls)
{
    if(row == 0 || col == 0)
    {
        row = 1;
        col = ls.size();
        channel = 1;
        data_p = new Data(row, col, channel);
    }

    int id = 0;
    for(auto item : ls)
    {
        if(id < row*col*channel)
            data_p->data[id++] = item;
        else
            break;
    }

    return (*this);
}

template<class T> T* _Matrix<T>::operator[](int n)
{
    if(data_p->refCount>1)
    {
        Data * tmp_p = data_p;
        --data_p->refCount;
        data_p = new Data(row, col, channel);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                for(int k=0;k<channel;k++)
                    data_p->data[i*col*channel+j*channel+k] = tmp_p->data[i*col*channel+j*channel+k];
            }
        }
    }
    return &(data_p->data[n * col * channel]);
}

template<class T> void _Matrix<T>::recreate(int _row, int _col, int _channel)
{
    if(data_p && --data_p->refCount == 0)
        delete data_p;

    row = _row;
    col = _col;
    channel = _channel;
    data_p = new Data(_row, _col, _channel);
}

template<class T> _Matrix<T> _Matrix<T>::transpose() const
{
    _Matrix<T> m(col, row);
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            m[j][i] = (*this)[i][j];
        }
    }
    return m;
}

template<class T> _Matrix<T> _Matrix<T>::dot(const _Matrix<T>& m) const
{
    _Matrix<T> _m(row, col);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
                _m[i][j] = (*this)[i][j] * m[i][j];
    return _m;
}

template<class T> _Matrix<T> _Matrix<T>::eye(int val)
{
    _Matrix<T> m(val, val);
    for(int i=0;i<val;i++)
        for(int j=0;j<val;j++)
        {
            if(i==j)
                m[i][j]=(T)1;
            else
                m[i][j]=(T)0;
        }
    return m;
}

template<class T> _Matrix<T> _Matrix<T>::zeros(int row, int col, int channel)
{
    _Matrix<T> m(row, col, channel);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            for(int k=0;k<channel;k++)
            {
                m[i][j*channel + k]=(T)0;
            }
    return m;
}

template<class T> _Matrix<T> _Matrix<T>::ones(int row, int col, int channel)
{
    _Matrix<T> m(row, col, channel);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            for(int k=0;k<channel;k++)
            {
                m[i][j*channel + k]=(T)1;
            }
    return m;
}

template<class T> _Matrix<T> _Matrix<T>::eye(int row, int col)
{
    _Matrix<T> m(row, col);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(i==j)
                m[i][j]=(T)1;
            else
                m[i][j]=(T)0;
        }
    return m;
}

template<class T> bool _Matrix<T>::isempty () const { return data_p == NULL; }

template<class T> T _Matrix<T>::trace () const
{
    int tr=0;
    for(int i=0;i<row;i++)
        tr += (*this)[i][i];
    return tr;
}
template<class T> _Matrix<T>::~_Matrix()
{
    if(--data_p->refCount==0)
        delete data_p;
}

template<class T> _Matrix<T>::Data::Data(int _row, int _col, int _channel):refCount(1)
{
     data =  new T[_row * _col * _channel];
     memset(data, 0, sizeof(*data));
}

template<class T> _Matrix<T>::Data::~Data()
{
    delete []data;
    data=NULL;
}

template<class T> _Matrix<T> conv(const _Matrix<T>& mat, const Matrix& kernel, bool normalize, bool ccorr)
{
    if(kernel.GetRow() != kernel.GetCol() || kernel.GetRow() % 2 ==0 || kernel.GetChannel() != mat.GetChannel())
    {
        //Error
    }

    int row = mat.GetRow();
    int col = mat.GetCol();
    int channel = mat.GetChannel();
    int kedge = kernel.GetRow();

    _Matrix<T> res = _Matrix<T>::zeros(row, col, channel);

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            for(int k=0;k<channel;k++)
            {
                T val = 0;
                int cnt=0;
                for(int m=0;m<=kedge;m++)
                    for(int n=0;n<=kedge;n++)
                    {
                        int y = i-(kedge/2)+m;
                        int x = j-(kedge/2)+n;

                        if(x>=0 && y>=0 && x<=col && y<=row)
                        {
                            if(ccorr)
                                val += kernel[m][n*channel+k] * mat[y][x*channel+k];
                            else
                                val += kernel[kedge-1-m][(kedge-1-n)*channel+k] * mat[y][x*channel+k];

                            cnt++;
                        }

                    }
                if(normalize)
                    res[i][j*channel+k] += val/(T)cnt;
                else
                    res[i][j*channel+k] += val;
            }
    return res;
}

template<class T> std::ostream& operator << (std::ostream& os, const _Matrix<T>& m)
{
    for(int i=0;i<m.GetRow();i++)
    {
        for(int j=0;j<m.GetCol();j++)
            os<<m[i][j]<<" ";
        os<<std::endl;
    }
    return os;
}

template<class T> _Matrix<T> operator * (const _Matrix<T>& m1, const _Matrix<T>& m2)
{
    int row1=m1.GetRow();
    int col1=m1.GetCol();
    int row2=m2.GetRow();
    int col2=m2.GetCol();

    _Matrix<T> _m(row1, col2);
    for (int i=0;i<row1;i++)
    {
        for (int j=0;j<col2;j++)
        {
            _m[i][j] = 0;
            for(int k=0;k<col1;k++)
            {
                _m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return _m;
}

template<class T, class _T> _Matrix<T> operator * (const _Matrix<T>& m, _T val)
{
    int row=m.GetRow();
    int col=m.GetCol();

    _Matrix<T> _m(row, col);
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            _m[i][j] = m[i][j] * val;
        }
    }
    return _m;
}

template<class T, class _T> _Matrix<T> operator * (_T val, const _Matrix<T>& m)
{
    int row=m.GetRow();
    int col=m.GetCol();

    _Matrix<T> _m(row, col);
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            _m[i][j] = m[i][j] * val;
        }
    }
    return _m;
}

template<class T> _Matrix<T> operator + (const _Matrix<T>& m1, const _Matrix<T>& m2)
{
    _Matrix<T> _m(m1.row, m1.col);
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m1.col;j++)
            _m[i][j] = m1[i][j] + m2[i][j];
    return _m;
}

template<class T, class _T> _Matrix<T> operator + (const _Matrix<T>& m, _T val)
{
    int _row = m.GetRow();
    int _col = m.GetCol();

    _Matrix<T> _m(_row, _col);
    for (int i=0;i<_row;i++)
    {
        for (int j=0;j<_col;j++)
        {
            _m[i][j] = m[i][j] + val;
        }
    }
    return _m;
}

template<class T, class _T> _Matrix<T> operator + (_T val, const _Matrix<T>& m)
{
    _Matrix<T> _m(m.GetRow(), m.GetCol());
    for (int i=0;i<m.GetRow();i++)
    {
        for (int j=0;j<m.GetCol();j++)
        {
            _m[i][j] = m[i][j] + val;
        }
    }
    return _m;
}

template<class T> _Matrix<T> operator - (const _Matrix<T>& m1, const _Matrix<T>& m2)
{
    assert(m1.GetSize() == m2.GetSize());
    int _row = m1.GetRow();
    int _col = m1.GetCol();

    _Matrix<T> _m(_row, _col);
    for(int i=0;i<_row;i++)
        for(int j=0;j<_col;j++)
            _m[i][j] = m1[i][j] - m2[i][j];
    return _m;
}

template<class T, class _T> _Matrix<T> operator - (const _Matrix<T>& m, _T val)
{
    int _row = m.GetRow();
    int _col = m.GetCol();

    _Matrix<T> _m(_row, _col);
    for (int i=0;i<_row;i++)
    {
        for (int j=0;j<_col;j++)
        {
            _m[i][j] = m[i][j] - val;
        }
    }
    return _m;
}

template<class T, class _T> _Matrix<T> operator - (_T val, const _Matrix<T>& m)
{
    int _row = m.GetRow();
    int _col = m.GetCol();

    _Matrix<T> _m(_row, _col);
    for (int i=0;i<_row;i++)
    {
        for (int j=0;j<_col;j++)
        {
            _m[i][j] = val - m[i][j];
        }
    }
    return _m;
}

template<class T> bool operator == (const _Matrix<T>& m1, const _Matrix<T>& m2)
{
    if((m1.row != m2.row) || (m1.col != m2.col))
        return false;
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m1.col;j++)
        {
            if(m1[i][j]!=m2[i][j])
                return false;
        }
    return true;
}

template<class T> bool operator != (const _Matrix<T>& m1, const _Matrix<T>& m2)
{
    if((m1.row != m2.row) || (m1.col != m2.col))
        return true;
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m1.col;j++)
        {
            if(m1[i][j]!=m2[i][j])
                return true;
        }
    return false;
}

} // !namespace CVLab

#endif //MODULES_CORE_TYPE_HPP_
