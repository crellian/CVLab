#ifndef MODULES_CORE_TYPE_H_
#define MODULES_CORE_TYPE_H_

#include <initializer_list>
#include <complex>
// Type for vector data
// Type Vector is for int8_t
template <class T>
class _Vector
{
public:
    _Vector();
    _Vector(int _len);
    _Vector(int _len, T val);
    _Vector(const T* _data, int _len);
    _Vector(const _Vector& v);

    //_Vector& operator = (std::intializer_list<T> ls);
    T& operator[](int idx);
    T& operator()(int idx);
    bool operator == (const _Vector& v) const;
    bool operator != (const _Vector& v) const;
    friend std::ostream& operator << (std::ostream& os, const _Vector<T>& v);

    void set_len(int _len);

    ~_Vector();

private:
    T* data;//SET?
    int len;
};

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
    _Size(const _Size& sz);

    T area() const;

    _Size& operator = (const _Size& s);
    bool operator == (const _Size& s) const;
    bool operator != (const _Size& s) const;

    T width, height;
};

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
    _Point3(const _Point3& p);

    _Point3& operator = (const _Point3& p);

    _Point3& operator + (const _Point3& p) const;
    bool operator == (const _Point3& p) const;
    bool operator != (const _Point3& p) const;
    bool operator <= (const _Point3& p) const;
    bool operator < (const _Point3& p) const;
    bool operator >= (const _Point3& p) const;
    bool operator > (const _Point3& p) const;
    //friend std::ostreram& operator << (std::stream& os, const _Point3& p) const;

    T dot_product(const _Point3& p1, const _Point3& p2) const;
    _Point3& cross_product(const _Point3& p1, const _Point3& p2) const;

    T x, y, z;
};

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
    _Point(const _Point& p);

    _Point& operator = (const _Point& p);

    _Point& operator + (const _Point& p) const;
    bool operator == (const _Point& p) const;
    bool operator != (const _Point& p) const;
    bool operator <= (const _Point& p) const;
    bool operator < (const _Point& p) const;
    bool operator >= (const _Point& p) const;
    bool operator > (const _Point& p) const;
    //friend std::ostreram& operator << (std::stream& os, const _Point& p) const;

    T dot_product(const _Point& p1, const _Point& p2) const;
    _Point3<T>& cross_product(const _Point& p1, const _Point& p2) const;

    T x, y;
};

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
    _Rect(const _Rect& r);
    _Rect(const _Size<T>& s, const _Point<T>& p);
    _Rect(const _Point<T>& p1, const _Point<T>& p2);

    _Rect& operator = (const _Rect& r);

    _Point<T>& getTL() const;
    _Point<T>& getBR() const;

    _Size<T>& getSize() const;

    T x, y , width, height;
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
    _Scalar(T v1, T v2 = 0, T v3 = 0, T v4 = 0);

    T& operator[] (int idx);
    bool operator == (const _Scalar& s) const;
    bool operator != (const _Scalar& s) const;
    _Scalar& operator += (const _Scalar& s);
    _Scalar& operator -= (const _Scalar& s);
    _Scalar& operator *= (T val);
    _Scalar& operator + (const _Scalar& s) const;
    _Scalar& operator -(const _Scalar& s) const;
    _Scalar& operator * (T val) const;
    //friend _Scalar& operator * (T val, const _Scalar& s) const;
    //friend std::ostream& operator << (std::ostream & os, const _Scalar<T>& s);

    void init(T val);
    _Scalar conj() const;
    bool isReal() const;

    T v[4];
};

typedef _Scalar<double>            Scalar;
typedef _Scalar<double>            Scalar64f;
typedef _Scalar<float>             Scalar32f;
typedef _Scalar<unsigned int>      Scalar32u;
typedef _Scalar<signed int>        Scalar32s;
typedef _Scalar<unsigned char>     Scalar8u;
typedef _Scalar<signed char>       Scalar8s;

#endif MODULES_CORE_TYPE_H_
