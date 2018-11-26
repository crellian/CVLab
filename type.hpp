#ifndef MODULES_CORE_TYPE_HPP_
#define MODULES_CORE_TYPE_HPP_
#include <stdio.h>

// Type for vector data
// Type Vector is for int8_t
template<class T> _Vector<T>::_Vector() :len(0), data(NULL){}
template<class T> _Vector<T>::_Vector(int _len) :len(_len), data(new T[_len]) {memset(data, 0, _len * sizeof(T));}
template<class T> _Vector<T>::_Vector(int _len, T val) :len(_len), data(new T[_len]) {memset(data, val, _len * sizeof(T));}
template<class T> _Vector<T>::_Vector(const T* _data, int _len) :data(_data), len(_len) {}
template<class T> _Vector<T>::_Vector(const _Vector<T>& v) :data(v.data), len(v.len) {}

template<class T> _Vector<T>& operator = (std::intializer_list<T> ls) {int id=0; for(auto item: ls) {data[id]=item; id++;} len = id; return (*this);}
template<class T> const T& _Vector<T>::operator[] (int idx) const {return *(data+idx);}
template<class T> T& _Vector<T>::operator[] (int idx) {return *(data+idx);}
template<class T> bool _Vector<T>::operator == (const _Vector<T>& v) const {if(len != v.len) return false; for(int i=0; i<len; i++) if((*this)[i] != v[i]) return false;}
template<class T> bool _Vector<T>::operator != (const _Vector<T>& v) const {return !((*this) == v);}
template<class T> std::ostream& operator << (std::ostream& os, const _Vector<T>& v) {for(int i=0;i<v.GetLen();i++) os<<(int)v[i]<<" "; return os;}

template<class T> void _Vector<T>::SetLen(int _len) const {T* _data=new T[_len]; for(int i=0;i<len && i<_len;i++) _data[i] = data[i]; delete [](data); data = _data; len=_len;}
template<class T> int _Vector<T>::GetLen() const {return len;}

template<class T> _Vector<T>::~_Vector() {delete []data; data=NULL;}


// Type for size data
template<class T> _Size<T>::_Size() :width(0), height(0) {}
template<class T> _Size<T>::_Size(T _width, T _height) :width(_width), height(_height) {}
template<class T> _Size<T>::_Size(const _Size<T>& s) :width(s.width), height(s.height) {}

template<class T> bool _Size<T>::operator == (const _Size<T>& s) const {return (width == s.width) && (height == s.height);}
template<class T> bool _Size<T>::operator != (const _Size<T>& s) const {return (width != s.width) || (height != s.height);}
template<class T> std::ostream& operator << (std::ostream& os, const _Size<T>& s) {return os << "(" << s.GetWidth() << "," << s.GetHeight() << ")";}

template<class T> T _Size<T>::area() const {return width*height;}

template<class T> void _Size<T>::SetWidth(T val) {width=val;}
template<class T> void _Size<T>::SetHeight(T val) {height=val;}
template<class T> T _Size<T>::GetWidth() const {return width;}
template<class T> T _Size<T>::GetHeight() const {return height;}

template<class T> _Size<T>::~_Size() {}


// Type for complex data
// Type Complex is for int8_t


// Type for 3d Point data
// Type Point3 is for int
template<class T> _Point3<T>::_Point3() :x(0),y(0),z(0) {};
template<class T> _Point3<T>::_Point3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {};
template<class T> _Point3<T>::_Point3(const _Point3& p) :x(p.x), y(p.y), z(p.z){};

template<class T> _Point3<T> _Point3<T>::operator + (const _Point3<T>& p) const {return {x + p.GetX(), y + p.GetY(), z + p.GetZ()};}
template<class T> bool _Point3<T>::operator == (const _Point3<T>& p) const {return (x == p.GetX()) && (y == p.GetY()) && (z == p.GetZ());}
template<class T> bool _Point3<T>::operator != (const _Point3<T>& p) const {return (x != p.GetX()) || (y != p.GetY()) || (z != p.GetZ());}
template<class T> bool _Point3<T>::operator <= (const _Point3<T>& p) const {return (x <= p.GetX()) && (y <= p.GetY()) && (z <= p.GetZ());}
template<class T> bool _Point3<T>::operator < (const _Point3<T>& p) const {return (x < p.GetX()) && (y < p.GetY()) && (z < p.GetZ());}
template<class T> bool _Point3<T>::operator >= (const _Point3<T>& p) const {return (x >= p.GetX()) && (y >= p.GetY()) && (z >= p.GetZ());}
template<class T> bool _Point3<T>::operator > (const _Point3<T>& p) const {return (x > p.GetX()) && (y > p.GetY()) && (z > p.GetZ());}
template<class T> std::ostream& operator << (std::ostream& os, const _Point3<T>& p) { return os << "(" << p.GetX() << "," << p.GetY() << "," << p.GetZ() << ")";}

template<class T> T _Point3<T>::DotPdt(const _Point3<T>& p) const {return (x * p.GetX()) + (y * p.GetY()) + (z * p.GetZ());}
template<class T> _Point3<T> _Point3<T>::CrossPdt(const _Point3<T>& p) const {return {(y * p.GetZ() - z * p.GetY()), (z * p.GetX() - x * p.GetZ()), (x * p.GetY() - y * p.GetX())};}

template<class T> void _Point3<T>::SetX(T val) {x=val;}
template<class T> void _Point3<T>::SetY(T val) {y=val;}
template<class T> void _Point3<T>::SetZ(T val) {z=val;}
template<class T> T _Point3<T>::GetX() const {return x;}
template<class T> T _Point3<T>::GetY() const {return y;}
template<class T> T _Point3<T>::GetZ() const {return z;}

template<class T> _Point3<T>::~_Point3() {}


// Type for 2d Point data
// Type Point is for int
template<class T> _Point<T>::_Point() :x(0),y(0) {};
template<class T> _Point<T>::_Point(T _x, T _y) :x(_x), y(_y) {};
template<class T> _Point<T>::_Point(const _Point& p) :x(p.x), y(p.y) {};

template<class T> _Point<T> _Point<T>::operator + (const _Point<T>& p) const {return {x + p.GetX(), y + p.GetY()};}
template<class T> bool _Point<T>::operator == (const _Point<T>& p) const {return (x == p.GetX()) && (y == p.GetY());}
template<class T> bool _Point<T>::operator != (const _Point<T>& p) const {return (x != p.GetX()) || (y != p.GetY());}
template<class T> bool _Point<T>::operator <= (const _Point<T>& p) const {return (x <= p.GetX()) && (y <= p.GetY());}
template<class T> bool _Point<T>::operator < (const _Point<T>& p) const {return (x < p.GetX()) && (y < p.GetY());}
template<class T> bool _Point<T>::operator >= (const _Point<T>& p) const {return (x >= p.GetX()) && (y >= p.GetY());}
template<class T> bool _Point<T>::operator > (const _Point<T>& p) const {return (x > p.GetX()) && (y > p.GetY());}
template<class T> std::ostream& operator << (std::ostream& os, const _Point<T>& p) { return os << "(" << p.GetX() << "," << p.GetY() << ")";}

template<class T> T _Point<T>::DotPdt(const _Point<T>& p) const {return (x * p.GetX()) + (y * p.GetY());}
template<class T> _Point3<T> _Point<T>::CrossPdt(const _Point<T>& p) const {return {0, 0, x * p.GetY() - y * p.GetX()};}

template<class T> void _Point<T>::SetX(T val) {x=val;}
template<class T> void _Point<T>::SetY(T val) {y=val;}
template<class T> T _Point<T>::GetX() const {return x;}
template<class T> T _Point<T>::GetY() const {return y;}

template<class T> _Point<T>::~_Point() {}


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

template<class T> _Rect<T>::~_Rect() {}


// Type for Scalar
// Type Scalar is for double

template<class T> _Scalar<T>::_Scalar() {v[0]=0; v[1]=0; v[2]=0; v[3]=0;}
template<class T> _Scalar<T>::_Scalar(T v1, T v2, T v3, T v4) {v[0]=v1; v[1]=v2; v[2]=v3; v[3]=v4;}
template<class T> _Scalar<T>::_Scalar(const _Scalar& s) {v[0]=s.v[0]; v[1]=s.v[1]; v[2]=s.v[2]; v[3]=s.v[3];}

template<class T> const T& _Scalar<T>::operator[] (int idx) const {return v[idx];}
template<class T> T& _Scalar<T>::operator[] (int idx) {return v[idx];}
template<class T> bool _Scalar<T>::operator == (const _Scalar<T>& s) const {return !((*this) != s);}
template<class T> bool _Scalar<T>::operator != (const _Scalar<T>& s) const {for(int i=0; i<4; i++) if(v[i] != s.v[i]) return false; return true;}
template<class T> _Scalar<T>& _Scalar<T>::operator += (const _Scalar<T>& s) {for(int i=0; i<4; i++) v[i] += s.v[i]; return (*this);}
template<class T> _Scalar<T>& _Scalar<T>::operator -= (const _Scalar<T>& s) {for(int i=0; i<4; i++) v[i] -= s.v[i]; return (*this);}
template<class T> _Scalar<T>& _Scalar<T>::operator *= (T val) {for(int i=0; i<4; i++) v[i] *= val; return (*this);}
template<class T> _Scalar<T> _Scalar<T>::operator + (const _Scalar<T>& s) const {return {v[0] + s.v[0], v[1] + s.v[1], v[2] + s.v[2], v[3] + s.v[3]};}
template<class T> _Scalar<T> _Scalar<T>::operator -(const _Scalar<T>& s) const {return {v[0] - s.v[0], v[1] - s.v[1], v[2] - s.v[2], v[3] - s.v[3]};}
template<class T> _Scalar<T> _Scalar<T>::operator * (T val) const {return {v[0] * val, v[1] * val, v[2] * val, v[3] * val};}
template<class T, class _T> _Scalar<T> operator * (_T val, const _Scalar<T>& s) {return {s.v[0] * val, s.v[1] * val, s.v[2] * val, s.v[3] * val};}
template<class T> std::ostream& operator << (std::ostream& os, const _Scalar<T>& s) {return os<<"["<<s.v[0]<<", "<<s.v[1]<<", "<<s.v[2]<<", "<<s.v[3]<<"]";}

template<class T> void _Scalar<T>::init(T val) {v[0] = v[1] = v[2] = v[3] = val;}
template<class T> _Scalar<T> _Scalar<T>::conj() const {return {v[0], -v[1], -v[2], -v[3]};}
template<class T> bool _Scalar<T>::isReal() const {return ((v[1] == 0) && (v[2] == 0) && (v[3] == 0));}

template<class T> _Scalar<T>::~_Scalar() {}


// Type for Matrix
template<class T> _Matrix<T>::_Matrix() :row(0), col(0), data_p(new Data()) {}
template<class T> _Matrix<T>::_Matrix(int _row, int _col) :row(_row), col(_col), data_p(new Data(_row, _col)){}
template<class T> _Matrix<T>::_Matrix(const _Matrix<T>& m) :row(m.row), col(m.col), data_p(m.data) {}

template<class T>
    _Matrix&
        _Matrix<T>::operator = (const Matrix& m)
        {

        }
/*template<class T>
    _Matrix&
       _Matrix<T>::operator = (std::initializer_list<T> ls)
       {
           for(auto item : ls)
           {

           }
       }*/

template<class T>
    _Matrix
        _Matrix<T>::transpose() const
        {
            _Matrix<T> m(row, col);
            for (int i=0;i<row;i++)
            {
                for (int j=0;j<col;j++)
                {
                    m[i][j] = (*this)[j][i];
                }
            }
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::dot(const _Matrix<T>& m) const
        {
            _Matrix<T> _m(row, col);
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    _m[i][j] = (*this)[i][j] * m[i][j];
            return _m;
        }

template<class T>
    _Matrix
        _Matrix<T>::zeros(int val)
        {
            _Matrix<T> m(val, val);
            memset(m.data, 0, (val*val) * sizeof(T));
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::ones(int val)
        {
            _Matrix<T> m(val, val);
            memset(m.data, 1, (val*val) * sizeof(T));
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::eye(int val)
        {
            _Matrix<T> m(val, val);
            for(int i=0;i<val;i++)
                for(int j=0;j<val;j++)
                {
                    if(i==j)
                        m[i][j]=1;
                    else
                        m[i][j]=0;
                }
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::zeros(int row, int col)
        {
            _Matrix<T> m(row, col);
            memset(m.data, 0, (val*val) * sizeof(T));
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::ones(int row, int col)
        {
            _Matrix<T> m(row, col);
            memset(m.data, 1, (val*val) * sizeof(T));
            return m;
        }
template<class T>
    _Matrix
        _Matrix<T>::eye(int row, int col)
        {
            _Matrix<T> m(row, col);
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                {
                    if(i==j)
                        m[i][j]=1;
                    else
                        m[i][j]=0;
                }
            return m;
        }
template<class T> bool _Matrix<T>::isempty () const { return data==NULL; }
template<class T>
    T
        _Matrix<T>::trace () const
        {
            int tr=0;
            for(int i=0;i<row;i++)
                tr += (*this)[i][i];
            return tr;
        }
template<class T> _Matrix<T>::~_Matrix() {}

template<class T> _Matrix<T>::Data::Data(const T* initVal):refCount(1)
{
     val=new T[strlen(initVal)+1];
     if(!(isempty()))
            {
                delete []data;
            }

            row = m.row;
            col = m.col;
            data =  new T[m.row * m.col];

            memcpy(data, m.data, (m.row * m.col) * sizeof(T));

            return (*this);
     memcpy(data, m.data, (m.row * m.col) * sizeof(T));
}

template<class T> _Matrix<T>::StringVal::~StringVal()
{
    delete []data;
    data=NULL;
}


template<class T>
    _Matrix<T>
        _Matrix<T>::conv(const _Matrix<T>& m1, const _Matrix<T>& m2)
        {

        }
template<class T>
    std::ostream&
        operator << (std::ostream& os, const _Matrix<T>& m)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                    os<<m[i][j]<<" ";
                os<<endl;
            }
            return os;
        }

template<class T>
    _Matrix<T>
        operator * (const Matrix<T>& m1, const Matrix<T>& m2)
        {
            _Matrix<T> _m(m1.row, m1.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = 0;
                    for(int k=0;k<m1.col;k++)
                    {
                        _m[i][j] += m1[i][k] * m2[k][j];
                    }
                }
            }
            return _m;
        }
template<class T, class _T>
    _Matrix<T>
        operator * (const Matrix<T>& m, _T val)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] * val;
                }
            }
            return _m;
        }
template<class T, class _T>
    _Matrix<T>
        operator * (_T val, const Matrix<T>& m)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] * val;
                }
            }
            return _m;
        }

template<class T>
    _Matrix<T>
        operator + (const Matrix<T>& m1, const Matrix<T>& m2)
        {
            _Matrix<T> _m(row, col);
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    _m[i][j] = (*this)[i][j] + m[i][j];
            return _m;
        }

template<class T, class _T>
    _Matrix<T>
        operator + (const Matrix<T>& m, _T val)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] + val;
                }
            }
            return _m;
        }

template<class T, class _T>
    _Matrix<T>
        operator + (_T val, const Matrix<T>& m)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] + val;
                }
            }
            return _m;
        }

template<class T>
    _Matrix<T>
        operator - (const Matrix<T>& m1, const Matrix<T>& m2)
        {
            _Matrix<T> _m(row, col);
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    _m[i][j] = (*this)[i][j] - m[i][j];
            return _m;
        }
template<class T, class _T>
    _Matrix<T>
        operator - (const Matrix<T>& m, _T val)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] - val;
                }
            }
            return _m;
        }
template<class T, class _T>
    _Matrix<T>
        operator - (_T val, const Matrix<T>& m)
        {
            _Matrix<T> _m(m.row, m.col);
            for (int i=0;i<m1.row;i++)
            {
                for (int j=0;j<m2.col;j++)
                {
                    _m[i][j] = m[i][j] - val;
                }
            }
            return _m;
        }

template<class T>
    bool
        operator == (const Matrix<T>& m1, const Matrix<T>& m2)
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
template<class T>
    bool
        operator != (const Matrix<T>& m1, const Matrix<T>& m2)
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


#endif //MODULES_CORE_TYPE_HPP_
