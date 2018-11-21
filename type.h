#ifndef MODULES_CORE_TYPE_H_
#define MODULES_CORE_TYPE_H_
// Type for size data
template<class T>
class _Size
{
public:

    _Size();
    _Size(T width, T height);
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
typedef std::complex<T> _Complex;

typedef _Complex<int8_t> Complex;
typedef _Complex<uint8_t> Complex8u;
typedef _Complex<int16_t> Complex16s;
typedef _Complex<uint16_t> Complex16u;
typedef _Complex<int32_t> Complex32s;
typedef _Complex<uint32_t> Complex32u;
typedef _Complex<float> Complex32f;
typedef _Complex<double> Complex64d;


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
    friend std::ostreram& operator << (std::stream& os, const _Point& p) const;

    T dot_product(const _Point& p1, const _Point& p2) const;
    _Point3& cross_product(const _Point& p1, const _Point& p2) const;

    bool inside(const _Rect<T>& r) const;

    T x, y;
};

typedef _Point<int>       Point;
typedef _Point<int>       Pointi;
typedef _Point<double>    Pointd;
typedef _Point<float>     Pointf;

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
    friend std::ostreram& operator << (std::stream& os, const _Point3& p) const;

    T dot_product(const _Point3& p1, const _Point3& p2) const;
    _Point3& cross_product(const _Point3& p1, const _Point3& p2) const;

    bool inside(const _Rect<T>& r) const;

    T x, y, z;
};

typedef _Point3<int>       Point3;
typedef _Point3<int>       Point3i;
typedef _Point3<double>    Point3d;
typedef _Point3<float>     Point3f;
#endif MODULES_CORE_TYPE_H_
