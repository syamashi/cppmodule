/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:42:41 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/22 14:40:36 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template<class T>
class Array
{
    private:
		T* _arr;
		int _size;
    public:
        Array();
        ~Array();
        Array(const Array<T> &src);
        Array(unsigned int n);

		int size() const;

        Array& operator=(const Array<T> &src);
		const T& operator[](const int index) const; // read
		T& operator[](const int index); // write
	class OutOfArrayException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

template<typename T>
Array<T>::Array() : _arr(NULL), _size(0){}

template<typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_arr = new T[n];
}

template<typename T>
Array<T>::Array(const Array<T> &src)
{
	this->_arr = new T[src._size];
	for (int i = 0; i < src._size; ++i)
		this->_arr[i] = src._arr[i];
	this->_size = src._size;
}

template<typename T>
int Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &src)
{
	if (this == &src)
		return (*this);
	delete [] this->_arr;
	this->_arr = new T[src._size];
	for (int i = 0; i < src._size; ++i)
		this->_arr[i] = src._arr[i];
	this->_size = src._size;
}

template<typename T>
const T& Array<T>::operator[](const int index) const // read[]
{
	if (index >= this->_size || index < 0)
		throw OutOfArrayException();
	return (this->_arr[index]);
}

template<typename T>
T& Array<T>::operator[](const int index) // write[]
{
	if (index >= this->_size || index < 0)
		throw OutOfArrayException();
	return (this->_arr[index]);
}

template<typename T>
const char *Array<T>::OutOfArrayException::what() const throw()
{
	return ("out of array");
}

#endif