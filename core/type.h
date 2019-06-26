#ifndef MODULES_CORE_TYPE_H_
#define MODULES_CORE_TYPE_H_

#include <initializer_list>
#include <complex>

namespace CVlab
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Type for vector data
// Type Vector is for int8_t
template <class T>
class _Vector
{
public:
    _Vector();
    explicit _Vector(int _len);
    _Vector(int _len, T val);
    _Vector(int _len, const T* _data);

    explicit _Vector(const _Vector<T>& v);

    _Vector& operator = (std::initializer_list<T> ls);
    _Vector& operator = (const _Vector<T>& v);        //deep copy
    const T& operator[](int idx) const;                  //For const Object
    T& operator[](int idx);
    void SetLen(int _len) const;
    int GetLen() const;

    ~_Vector();

private:
    int len;
    T* data;
};

template<class T> bool operator == (const _Vector<T>& v1, const _Vector<T>& v2);
template<class T> bool operator != (const _Vector<T>& v1, const _Vector<T>& v2);
template<class T> std::ostream& operator << (std::ostream& os, const _Vector<T>& v);

typedef _Vector<int8_t>      Vector;
typedef _Vector<uint8_t>     Vector8u;
typedef _Vector<int8_t>      Vector8s;
typedef _Vector<uint16_t>    Vector16u;
typedef _Vector<int16_t>     Vector16s;
typedef _Vector<float>       Vector32f;
typedef _Vector<double>      Vector64d;


// Type for size data
template<class T>
class _Size
{
public:
    _Size();
    _Size(T _width, T _height);
    explicit _Size(const _Size<T>& sz);

    T area() const;

    void SetWidth(T val);
    void SetHeight(T val);
    T GetWidth() const;
    T GetHeight() const;

    ~_Size() = default;

private:
    T width, height;
};

template<class T> bool operator == (const _Size<T>& s1, const _Size<T>& s2);
template<class T> bool operator != (const _Size<T>& s1, const _Size<T>& s2);
template<class T> std::ostream& operator << (std::ostream& os, const _Size<T>& s);

typedef _Size<int>       Size;
typedef _Size<int>       Sizei;
typedef _Size<double>    Sized;
typedef _Size<float>     Sizef;


// Type for complex data
// Type Complex is for int8_t
template<class T>
using _Complex1 = std::complex<T>;

typedef _Complex1<int8_t>   Complex;
typedef _Complex1<uint8_t>  Complex8u;
typedef _Complex1<int16_t>  Complex16s;
typedef _Complex1<uint16_t> Complex16u;
typedef _Complex1<int32_t>  Complex32s;
typedef _Complex1<uint32_t> Complex32u;
typedef _Complex1<float>    Complex32f;
typedef _Complex1<double>   Complex64d;


// Type for 3d Point data
// Type Point3 is for int
template<class T>
class _Point3
{
public:

    _Point3();
    _Point3(T _x, T _y, T _z);
    explicit _Point3(const _Point3<T>& p);

    T DotPdt(const _Point3<T>& p) const;
    _Point3 CrossPdt(const _Point3<T>& p) const;

    void SetX(T val);
    void SetY(T val);
    void SetZ(T val);
    T GetX() const;
    T GetY() const;
    T GetZ() const;

    ~_Point3() = default;

private:
    T x, y, z;
};

template<class T> _Point3<T> operator + (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator == (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator != (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator <= (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator < (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator >= (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> bool operator > (const _Point3<T>& p1, const _Point3<T>& p2);
template<class T> std::ostream& operator << (std::ostream& os, const _Point3<T>& p);

typedef _Point3<int>       Point3;
typedef _Point3<int>       Point3i;
typedef _Point3<double>    Point3d;
typedef _Point3<float>     Point3f;


// Type for 2d Point data
// Type Point is for int
template<class T>
class _Point
{
public:

    _Point();
    _Point(T _x, T _y);
    explicit _Point(const _Point<T>& p);

    //Overflow?
    T DotPdt(const _Point<T>& p) const;
    _Point3<T> CrossPdt(const _Point<T>& p) const;

    void SetX(T val);
    void SetY(T val);
    T GetX() const;
    T GetY() const;

    ~_Point() = default;

private:
    T x, y;
};
template<class T> _Point<T> operator + (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator == (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator != (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator <= (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator < (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator >= (const _Point<T>& p1, const _Point<T>& p2);
template<class T> bool operator > (const _Point<T>& p1, const _Point<T>& p2);
template<class T> std::ostream& operator << (std::ostream& os, const _Point<T>& p);

typedef _Point<int>       Point;
typedef _Point<int>       Pointi;
typedef _Point<double>    Pointd;
typedef _Point<float>     Pointf;



// Type for Rectangle
// Type Rect is for int
template<class T>
class _Rect
{
public:
    _Rect();
    _Rect(T _width, T _height, T _x = 0, T _y = 0);
    explicit _Rect(const _Rect& r);
    _Rect(const _Size<T>& s, const _Point<T>& p);
    _Rect(const _Point<T>& p1, const _Point<T>& p2);

    _Point<T> GetTL() const;
    _Point<T> GetBR() const;
    _Size<T> GetSize() const;
    bool contain(const _Point<T>& p) const;

    void SetWidth(T val);
    void SetHeight(T val);
    T GetWidth() const;
    T GetHeight() const;
    void SetX(T val);
    void SetY(T val);
    T GetX() const;
    T GetY() const;

    ~_Rect() = default;

private:
    T width, height, x, y;
};

typedef _Rect<int>    Rect;
typedef _Rect<int>    Rect_int;
typedef _Rect<float>  Rect_float;
typedef _Rect<double> Rect_double;

// Type for Scalar
// Type Scalar is for double
template<class T>
class _Scalar
{
public:
    _Scalar();
    explicit _Scalar(T v1, T v2 = 0, T v3 = 0, T v4 = 0);
    explicit _Scalar(const _Scalar<T>& s);

    const T& operator[] (int idx) const;
    T& operator[] (int idx);

    void init(T val);
    _Scalar conj() const;
    bool isReal() const;

    ~_Scalar() = default;

private:
    T v[4];
};

template<class T> bool operator == (const _Scalar<T>& s1, const _Scalar<T>& s2);
template<class T> bool operator != (const _Scalar<T>& s1, const _Scalar<T>& s2);
template<class T> _Scalar<T>& operator += (_Scalar<T>& s1, const _Scalar<T>& s2);
template<class T> _Scalar<T>& operator -= (_Scalar<T>& s1, const _Scalar<T>& s2);
template<class T, class _T> _Scalar<T>& operator *= (_Scalar<T>& s, _T val);
template<class T> _Scalar<T> operator + (const _Scalar<T>& s1, const _Scalar<T>& s2);
template<class T> _Scalar<T> operator - (const _Scalar<T>& s1, const _Scalar<T>& s2);
template<class T, class _T> _Scalar<T> operator * (const _Scalar<T>& s, _T val);
template<class T, class _T> _Scalar<T> operator * (_T val, const _Scalar<T>& s);
template<class T> std::ostream& operator << (std::ostream& os, const _Scalar<T>& s);

typedef _Scalar<double>            Scalar;
typedef _Scalar<double>            Scalar64f;
typedef _Scalar<float>             Scalar32f;
typedef _Scalar<unsigned int>      Scalar32u;
typedef _Scalar<signed int>        Scalar32s;
typedef _Scalar<unsigned char>     Scalar8u;
typedef _Scalar<signed char>       Scalar8s;


// Type for Matrix
template<class T>
class _Matrix
{
public:
    _Matrix();
    _Matrix(int _row, int _col, int _channel = 1);
	explicit _Matrix(const _Size<int> s, int _channel = 1);
    explicit _Matrix(const _Matrix& m);

    _Matrix<T>& operator = (const _Matrix<T>& m);
    _Matrix<T>& operator = (std::initializer_list<T> ls);
    T* operator[](int n);                                       //for writing operation, copy-on-write
    const T* operator[](int n) const {return &(data_p->data[n * col * channel]);}
    void recreate(int _row, int _col, int _channel = 1);

    _Matrix<T> transpose() const;
    _Matrix<T> dot(const _Matrix<T>& m) const;

    //Matlab-like
    //_Matrix inv() const;
    static _Matrix<T> eye(int val);
    static _Matrix<T> zeros(int row, int col, int channel = 1);
	static _Matrix<T> ones(int row, int col, int channel = 1);
	static _Matrix<T> eye(int row, int col);
	bool isempty () const;
    //T rank() const;
    T trace() const;
    int GetChannel() const {return channel;}
    int GetRow() const {return row;}
    int GetCol() const {return col;}
    _Size<int> GetSize() const {return {col, row};}

    ~_Matrix();

private:

    struct Data
    {
        int refCount;
        T* data;
        Data(int _row, int _col, int _channel);
        ~Data();
    };

    int channel;
    int row, col;
    Data* data_p;
};

typedef _Matrix<double>             Matrix;
typedef _Matrix<double>             Matrix64f;
typedef _Matrix<float>              Matrix32f;
typedef _Matrix<signed int>         Matrix32s;
typedef _Matrix<unsigned int>       Matrix32u;
typedef _Matrix<signed short>       Matrix16s;
typedef _Matrix<unsigned short>     Matrix16u;
typedef _Matrix<signed char>        Matrix8s;
typedef _Matrix<unsigned char>      Matrix8u;

template<class T> _Matrix<T> conv(const _Matrix<T>& mat, const Matrix64f& core, bool normalize=true, bool ccorr=true);
template<class T> std::ostream& operator << (std::ostream& os, const _Matrix<T>& m);

template<class T> _Matrix<T> operator * (const _Matrix<T>& m1, const _Matrix<T>& m2);
template<class T, class _T> _Matrix<T> operator * (const _Matrix<T>& m, _T val);
template<class T, class _T> _Matrix<T> operator * (_T val, const _Matrix<T>& m);

template<class T> _Matrix<T> operator + (const _Matrix<T>& m1, const _Matrix<T>& m2);
template<class T, class _T> _Matrix<T> operator + (const _Matrix<T>& m, _T val);
template<class T, class _T> _Matrix<T> operator + (_T val, const _Matrix<T>& m);

template<class T> _Matrix<T> operator - (const _Matrix<T>& m1, const _Matrix<T>& m2);
template<class T, class _T> _Matrix<T> operator - (const _Matrix<T>& m, _T val);
template<class T, class _T> _Matrix<T> operator - (_T val, const _Matrix<T>& m);

template<class T> bool operator == (const _Matrix<T>& m1, const _Matrix<T>& m2);
template<class T> bool operator != (const _Matrix<T>& m1, const _Matrix<T>& m2);

} // !namespace CVLab

#include "C:\Users\Lenovo\Desktop\OpencvLib-master\type.hpp"
#endif //MODULES_CORE_TYPE_H_
