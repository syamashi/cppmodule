/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:43:11 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/27 18:42:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
}

Span::Span(Span const &src)
{
    *this = src;
}

Span::Span(int N) : _N(N), _size(0)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span &src)
{
    if (this == &src)
        return (*this);
	_N = src._N;
	_size = src._size;
	_vec = src._vec;
    return (*this);
}

void Span::addNumber(const int &n)
{
	if (_size >= _N)
		throw (FilledException());
	_vec.push_back(n);
	++_size;
}

unsigned int Span::shortestSpan()
{
	if (_size < 2)
		throw (NotEnoughSizeException());
	std::sort(_vec.begin(), _vec.end());
	unsigned int ret = _vec[1] - _vec[0];
	for (unsigned int i = 2; i < _size; ++i)
	{
		unsigned int val = _vec[i] - _vec[i - 1];
		if (ret > val)
			ret = val;
	}
	return (ret);
}

unsigned int Span::longestSpan()
{
	if (_size < 2)
		throw (NotEnoughSizeException());
	std::sort(_vec.begin(), _vec.end());
	return (_vec[_size - 1] - _vec[0]);
}

const char *Span::FilledException::what() const throw()
{
	return ("vector is filled");
}

const char *Span::NotEnoughSizeException::what() const throw()
{
	return ("not enough size");
}
