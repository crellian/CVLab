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

    _Size& operator = (const _Size& s);
    T area() const;

    T width, height;
};

typedef _Size<int>       Size;
typedef _Size<double>    Sized;
typedef _Size<float>     Sizef;

template<T> bool operator == (const _Size<T>& s1, const _Size<T>&s2) const;

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


// Type for Point data
template<class T>
class _Point
{
public:

    _Point();
    _Point(T x, T y);
    _Point(const _Point& p);

    _Point<T>& operator = (const _Point<T>& p);

    T x, y;
};

#endif MODULES_CORE_TYPE_H_
