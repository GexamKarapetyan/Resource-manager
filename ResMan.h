#ifndef _HEADER_
#define _HEADER_

#include<iostream>
template <typename T>

class RM
{
public://ctors and dtor
	RM(T* src);
	RM (const RM<T>&& src) noexcept;
	~RM();
public://operators
	T& operator *();
	T* operator ->();
private:
	T* ptr;
	RM(const RM<T>& src) = delete;
	RM& operator =(const RM<T>& src) = delete;
};

//implementation
template <typename T>
RM <T>::RM(T* src)
{
	ptr = src;
}

template <typename T>
RM<T>::~RM()
{
	delete ptr;
}

template <typename T>
RM<T>::RM(const RM<T>&& src) noexcept
{
	ptr = src;
	src = nullptr;
}

template <typename T>
T& RM<T>::operator *()
{
	return *ptr;
}

template <typename T>
T* RM<T>::operator ->()
{
	return ptr;
}

#endif // !_HEADER_