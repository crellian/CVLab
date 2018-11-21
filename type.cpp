// Type for vector data
// Type Vector is for int8_t
template<class T> _Vector<T>::_Vector() {};
template<class T> _Vector<T>::_Vector(T _len) :len(_len) { data=new T[_len]; for(int i=0; i<_len; i++) data[i]=0;}
template<class T> _Vector<T>::_Vector(int _len, T val) :len(_len) { data=new T[_len]; for(int i=0; i<_len; i++) data[i]=val;}
template<class T> _Vector<T>::_Vector(const T* _data, int _len) :data(_data), len(_len) {}
template<class T> _Vector<T>::_Vector(const _Vector& v) :data(v.data), len(v.len) {}
template<class T> _Vector<T>::_Vector& operator = (std::intializer_list<T> ls) { int id=0; for(auto item: ls) { this->data[id]=item; id++; } this->len = id; return *this; }
template<class T> _Vector<T>::
template<class T> _Vector<T>::
template<class T> _Vector<T>::


// Type for size data
template<class T> _Size<T>::_Size() :width(0), height(0) {}
template<class T> _Size<T>::_Size(T _width, T _height) :width(_width), height(_height) {}
template<class T> _Size<T>::_Size(const _Size<T>& s) :width(s.width), height(s.height) {}

template<class T> bool _Size<T>::operator == (const _Size<T>& s) const {return (this->width == s.width) && (this->height == s.height);}
template<class T> bool _Size<T>::operator != (const _Size<T>& s) const {return (this->width != s.width) || (this->height != s.height);}

template<class T> T _Size<T>::area() const { return width*height; }

// Type for complex data
// Type Complex is for int8_t


// Type for 2d Point data
// Type Point is for int
template<class T> _Point<T>::_Point() :x(0),y(0);
template<class T> _Point<T>::_Point(T _x, T _y) :x(_x), (_y);
template<class T> _Point<T>::_Point(const _Point& p) :x(p.x), y(p.y);


template<class T> _Poin<T>t& _Point<T>::operator + (const _Point<T>& p) const {return {this->x + p.x, this->y + p.y};}
template<class T> bool _Point<T>::operator == (const _Point<T>& p) const {return (this->x == p.y) && (this->x == p.y);}
template<class T> bool _Point<T>::operator != (const _Point<T>& p) const {return (this->x != p.y) || (this->x != p.y);}
template<class T> bool _Point<T>::operator <= (const _Point<T>& p) const {return (this->x <= p.y) && (this->x <= p.y);}
template<class T> bool _Point<T>::operator < (const _Point<T>& p) const {return (this->x < p.y) && (this->x < p.y);}
template<class T> bool _Point<T>::operator >= (const _Point<T>& p) const {return (this->x >= p.y) && (this->x >= p.y);}
template<class T> bool _Point<T>::operator > (const _Point<T>& p) const {return (this->x > p.y) && (this->x > p.y);}
template<class T> friend std::ostreram& operator << (std::stream& os, const _Point<T>& p) const { os << "(" << p.x << "," << p.y << ")"; return os;}

template<class T> T _Point<T>::dot_product(const _Point<T>& p1, const _Point<T>& p2) const {return (p1.x * p2.x) + (p1.y * p2.y);}
template<class T> _Point3<T>& _Point<T>::cross_product(const _Point<T>& p1, const _Point<T>& p2) const {return ;} //

template<class T> bool _Point<T>::inside(const _Rect<T>& r) const;//
