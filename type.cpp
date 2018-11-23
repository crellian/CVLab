#include "type.h"

// Type for vector data
// Type Vector is for int8_t
export template<class T> _Vector<T>::_Vector() :len(0), data(NULL){}
export template<class T> _Vector<T>::_Vector(int _len) :len(_len) {data=new T[_len]; for(int i=0; i<_len; i++) data[i]=0;}
export template<class T> _Vector<T>::_Vector(int _len, T val) :len(_len) { data=new T[_len]; for(int i=0; i<_len; i++) data[i]=val;}
export template<class T> _Vector<T>::_Vector(const T* _data, int _len) :data(_data), len(_len) {}
export template<class T> _Vector<T>::_Vector(const _Vector<T>& v) :data(v.data), len(v.len) {}

//template<class T> _Vector& _Vector<T>::operator = (std::intializer_list<T> ls) {int id=0; for(auto item: ls) { data[id]=item; id++; } len = id; return *this;}
template<class T> T& _Vector<T>::operator[](int idx) {return *(data+idx);}
template<class T> T& _Vector<T>::operator()(int idx) {return *(data+idx);}
template<class T> bool _Vector<T>::operator == (const _Vector<T>& v) const {if(len != v.len) return false; for(int i=0; i<len; i++) if((*this)[i] != v[i]) return false;}
template<class T> bool _Vector<T>::operator != (const _Vector<T>& v) const {return !((*this) == v);}
template<class T> std::ostream& operator << (std::ostream& os, const _Vector<T>& v) {for(int i=0; i<v.len; i++) os<<v[i]<<"\n"; return os;}

template<class T> void _Vector<T>::set_len(int _len) {T* _data=new T[_len]; for(int i=0;i<len && i<_len;i++) _data[i] = data[i]; delete [](data); data = _data; len=_len;}

template<class T> _Vector<T>::~_Vector() {delete []data;}

// Type for size data
template<class T> _Size<T>::_Size() :width(0), height(0) {}
template<class T> _Size<T>::_Size(T _width, T _height) :width(_width), height(_height) {}
template<class T> _Size<T>::_Size(const _Size<T>& s) :width(s.width), height(s.height) {}

template<class T> bool _Size<T>::operator == (const _Size<T>& s) const {return (width == s.width) && (height == s.height);}
template<class T> bool _Size<T>::operator != (const _Size<T>& s) const {return (width != s.width) || (height != s.height);}

template<class T> T _Size<T>::area() const { return width*height; }


// Type for complex data
// Type Complex is for int8_t


// Type for 3d Point data
// Type Point3 is for int
template<class T> _Point3<T>::_Point3() :x(0),y(0),z(0) {};
template<class T> _Point3<T>::_Point3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {};
template<class T> _Point3<T>::_Point3(const _Point3& p) :x(p.x), y(p.y), z(p.z){};


template<class T> _Point3<T>& _Point3<T>::operator + (const _Point3<T>& p) const {return {x + p.x, y + p.y, z + p.z};}
template<class T> bool _Point3<T>::operator == (const _Point3<T>& p) const {return (x == p.x) && (y == p.y) && (z == p.z);}
template<class T> bool _Point3<T>::operator != (const _Point3<T>& p) const {return (x != p.x) || (y != p.y) || (z != p.z);}
template<class T> bool _Point3<T>::operator <= (const _Point3<T>& p) const {return (x <= p.x) && (y <= p.y) && (z <= p.z);}
template<class T> bool _Point3<T>::operator < (const _Point3<T>& p) const {return (x < p.x) && (y < p.y) && (z < p.z);}
template<class T> bool _Point3<T>::operator >= (const _Point3<T>& p) const {return (x >= p.x) && (y >= p.y) && (z >= p.z);}
template<class T> bool _Point3<T>::operator > (const _Point3<T>& p) const {return (x > p.x) && (y > p.y) && (z > p.z);}
//template<class T> std::ostreram& operator << (std::stream& os, const _Point3<T>& p) const { os << "(" << p.x << "," << p.y << "," << p.z << ")"; return os;}

template<class T> T _Point3<T>::dot_product(const _Point3<T>& p1, const _Point3<T>& p2) const {return (p1.x * p2.x) + (p1.y * p2.y) + (p1.z * p2.z);}
template<class T> _Point3<T>& _Point3<T>::cross_product(const _Point3<T>& p1, const _Point3<T>& p2) const {return {(p1.y * p2.z - p1.z * p2.y), (p1.z * p2.x - p1.x * p2.z), (p1.x * p2.y - p1.y * p2.x)};} //


// Type for 2d Point data
// Type Point is for int
template<class T> _Point<T>::_Point() :x(0),y(0) {};
template<class T> _Point<T>::_Point(T _x, T _y) :x(_x), y(_y) {};
template<class T> _Point<T>::_Point(const _Point& p) :x(p.x), y(p.y) {};


template<class T> _Point<T>& _Point<T>::operator + (const _Point<T>& p) const {return {x + p.x, y + p.y};}
template<class T> bool _Point<T>::operator == (const _Point<T>& p) const {return (x == p.x) && (y == p.y);}
template<class T> bool _Point<T>::operator != (const _Point<T>& p) const {return (x != p.x) || (y != p.y);}
template<class T> bool _Point<T>::operator <= (const _Point<T>& p) const {return (x <= p.x) && (y <= p.y);}
template<class T> bool _Point<T>::operator < (const _Point<T>& p) const {return (x < p.x) && (y < p.y);}
template<class T> bool _Point<T>::operator >= (const _Point<T>& p) const {return (x >= p.x) && (y >= p.y);}
template<class T> bool _Point<T>::operator > (const _Point<T>& p) const {return (x > p.x) && (y > p.y);}
//template<class T> std::ostreram& operator << (std::stream& os, const _Point<T>& p) const { os << "(" << p.x << "," << p.y << ")"; return os;}

template<class T> T _Point<T>::dot_product(const _Point<T>& p1, const _Point<T>& p2) const {return (p1.x * p2.x) + (p1.y * p2.y);}
template<class T> _Point3<T>& _Point<T>::cross_product(const _Point<T>& p1, const _Point<T>& p2) const {return ;} //


// Type for Rectangle
// Type Rect is for int
template<class T> _Rect<T>::_Rect() :width(0), height(0), x(0), y(0) {}
template<class T> _Rect<T>::_Rect(T _width, T _height, T _x, T _y) :width(_width), height(_height), x(_x), y(_y) {}
template<class T> _Rect<T>::_Rect(const _Rect<T>& r) :width(r.width), height(r.height), x(r.x), y(r.y) {}
template<class T> _Rect<T>::_Rect(const _Size<T>& s, const _Point<T>& p) :width(s.width), height(s.height), x(p.x), y(p.y) {}
template<class T> _Rect<T>::_Rect(const _Point<T>& p1, const _Point<T>& p2) :width(p1.x), height(p1.y), x(p2.x), y(p2.y) {}

template<class T> _Rect<T>& _Rect<T>::operator = (const _Rect<T>& r) {return {width=r.width, height=r.height, x=r.x, y=r.y};};

template<class T> _Point<T>& _Rect<T>::getTL() const {return {x, y};}
template<class T> _Point<T>& _Rect<T>::getBR() const {return {x+width, y+height};}

template<class T> _Size<T>& _Rect<T>::getSize() const {return{width, height};}


// Type for Scalar
// Type Scalar is for double

template<class T> _Scalar<T>::_Scalar() {v[0]=0; v[1]=0; v[3]=0; v[4]=0;}
template<class T> _Scalar<T>::_Scalar(T v1, T v2, T v3, T v4) {v[0]=v1; v[1]=v2; v[3]=v3; v[4]=v4;}

template<class T> T& _Scalar<T>::operator[] (int idx) {return v[idx];}
template<class T> bool _Scalar<T>::operator == (const _Scalar<T>& s) const {return !((*this) != s);}
template<class T> bool _Scalar<T>::operator != (const _Scalar<T>& s) const {for(int i=0; i<4; i++) if(v[i] != s.v[i]) return false;}
template<class T> _Scalar<T>& _Scalar<T>::operator += (const _Scalar<T>& s) {for(int i=0; i<4; i++) v[i] += s.v[i]; return (*this);}
template<class T> _Scalar<T>& _Scalar<T>::operator -= (const _Scalar<T>& s) {for(int i=0; i<4; i++) v[i] -= s.v[i]; return (*this);}
template<class T> _Scalar<T>& _Scalar<T>::operator *= (T val) {for(int i=0; i<4; i++) v[i] *= val; return (*this);}
template<class T> _Scalar<T>& _Scalar<T>::operator + (const _Scalar<T>& s) const {return {v[0] + s.v[0], v[1] + s.v[1], v[2] + s.v[2], v[3] + s.v[3]};}
template<class T> _Scalar<T>& _Scalar<T>::operator -(const _Scalar<T>& s) const {return {v[0] - s.v[0], v[1] - s.v[1], v[2] - s.v[2], v[3] - s.v[3]};}
template<class T> _Scalar<T>& _Scalar<T>::operator * (T val) const {return {v[0] * val, v[1] * val, v[2] * val, v[3] * val};}
//template<class T> _Scalar<T>& _Scalar<T>::operator * (T val, const _Scalar<T>& s) const {return {s.v[0] * val, s.v[1] * val, s.v[2] * val, s.v[3] * val};}
//template<class T> std::ostream& _Scalar<T>::operator << (std::ostream & os, const _Scalar<T>& s) {return os<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;}

template<class T> void _Scalar<T>::init(T val) {v[0]=val; v[1]=val; v[3]=val; v[4]=val;}
template<class T> _Scalar<T> _Scalar<T>::conj() const {}
template<class T> bool _Scalar<T>::isReal() const {}
