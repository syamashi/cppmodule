/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:43:44 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/30 11:51:29 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : rvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : rvalue(n << this->bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : rvalue(roundf((float)n * (1 << this->bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &src)
 		return (*this);
	if (this == &src)
 		return (*this);
	this->rvalue = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->rvalue);
}

void Fixed::setRawBits( int const raw )
{
	this->rvalue = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->rvalue / (1 << this->bits));
}

int Fixed::toInt( void ) const
{
	return (this->rvalue / (1 << this->bits));
}

std::ostream& operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return o;
}
