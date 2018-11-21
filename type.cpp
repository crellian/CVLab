
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


