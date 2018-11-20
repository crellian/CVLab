template<class T> _Size<T>::_Size() :width(0), height(0) {}
template<class T> _Size<T>::_Size(T _width, T _height) :width(_width), height(_height) {}
template<class T> _Size<T>::_Size(const _Size& s) :width(s.width), height(s.height) {}

template<class T> T _Size<T>::area() const { return width*height; }

template<class T> bool _Size<T>::operator == (const _Size<T>& s1, const _Size<T>& s2) const {return (s1.width==s2.width) && (s2.height==s2.height)}
template<class T> bool _Size<T>::operator != (const _Size<T>& s1, const _Size<T>& s2) const {return (s1.width!=s2.width) || (s2.height!=s2.height)}

