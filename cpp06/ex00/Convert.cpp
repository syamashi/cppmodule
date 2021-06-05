/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:49:24 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/05 22:48:30 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _input("")
{
}

Convert::Convert(Convert const &src) : _input(src._input)
{
    *this = src;
}

Convert::Convert(const std::string &input) : _c(0), _i(0), _f(0.0), _d(0.0), _input(input), _type(0)
{
	_type = get_type();
	if (_type <= TYPE_NAN)
		ft_limits();
	if (_type == TYPE_C)
		ft_stoc();
	if (_type == TYPE_I)
		ft_stoi();
	if (_type == TYPE_F)
		ft_stof();
	if (_type == TYPE_D)
		ft_stod();
}

Convert::~Convert()
{
}

Convert& Convert::operator=(const Convert &src)
{
    if (this == &src)
        return (*this);
	this->_type = src._type;
	this->_c = src._c;
	this->_i = src._i;
	this->_f = src._f;
	this->_d = src._d;
    return (*this);
}

int Convert::get_type()
{
	std::string strs[] = {"+inf", "+inff", "-inf", "-inff", "nan", "nanf"};
	for (int i = 0; i < 6; i++)
	{
		if (_input == strs[i])
			return (i / 2);
	}

	int input_len = _input.size();
	if (input_len == 1 && !std::isdigit(_input[0]))
		return (TYPE_C);

	int id = 0;
	if (_input[id] == '+' || _input[id] == '-')
		id++;
	while (isdigit(_input[id]))
		id++;
	if (id == input_len)
		return (TYPE_I);

	if (_input[id] != '.' || !isdigit(_input[++id]))
		throw (Convert::InvalidValueException());
	while (isdigit(_input[id]))
		id++;
	if (id == input_len)
		return (TYPE_D);
	if (_input[id] == 'f')
		id++;
	if (id == input_len)
		return (TYPE_F);
	throw (Convert::InvalidValueException());
}

void Convert::ft_limits()
{
	std::string limits[] = {"+inf", "-inf", "nan"};
	put_char("impossible");
	put_int("impossible");
	put_float(limits[_type] + "f");
	put_double(limits[_type]);
}

void Convert::ft_stoc()
{
	_c = static_cast<char>(_input[0]);
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
	put_char(_c);
	put_int(_i);
	put_float(_f);
	put_double(_d);
}

void Convert::ft_stoi()
{
	int id = 0;
	int sign = 1;

	if (_input[id] == '-')
		sign = -1;
	if (_input[id] == '+' || _input[id] == '-')
		++id;
	while (std::isdigit(_input[id]))
	{
		int num = _input[id] - '0';
		if ((_i * 10) / 10 != _i)
			throw (Convert::OverflowIntException());
		_i = _i * 10 + num * sign;
		if ((_i < 0 && sign > 0) || (_i > 0 && sign < 0))
			throw (Convert::OverflowIntException());
		id++;
	}

	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
	if (_i > 127 || _i < 0)
		put_char("impossible");
	else
		put_char(_c);
	put_int(_i);
	put_float(_f);
	put_double(_d);
}

void Convert::ft_stof()
{
	std::stringstream s(_input);
	s >> _f;
	_c = static_cast<char>(_f);
	_i = static_cast<int>(_f);
	_d = static_cast<double>(_f);
	float fint = 0;
	float ffract = std::modf(_f, &fint);
	ffract = roundf(ffract * 10.0) / 10.0;
	_f = fint + ffract;
	if (_f > 127 || _f < 0)
		put_char("impossible");
	else
		put_char(_c);
	if (_i != fint)
		put_int("impossible");
	else
		put_int(_i);
	put_float(_f);
	put_double(_d);
}

void Convert::ft_stod()
{
	std::stringstream s(_input);
	s >> _d;
	_c = static_cast<char>(_d);
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
	double dint = 0;
	double dfract = std::modf(_d, &dint);
	dfract = round(dfract * 10.0) / 10.0;
	_d = dint + dfract;
	if (_d > 127 || _d < 0)
		put_char("impossible");
	else
		put_char(_c);
	if (_i != dint)
		put_int("impossible");
	else
		put_int(_i);
	put_float(_f);
	put_double(_d);
}

void Convert::put_char(const std::string &c)
{
	std::cout << "char: " << c << std::endl;
}

void Convert::put_char(const char &c)
{
	if (_c < 32 || _c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
}

void Convert::put_int(const std::string &i)
{
	std::cout << "int: " << i << std::endl;
}

void Convert::put_int(const int &i)
{
	std::cout << "int: " << i << std::endl;
}

void Convert::put_float(const std::string &f)
{
	std::cout << "float: " << f << std::endl;
}

void Convert::put_float(const float &f)
{
	float fint = 0;
	float ffract = std::modf(f, &fint);
	if (ffract == 0.0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << 'f' << std::endl;
}

void Convert::put_double(const std::string &d)
{
	std::cout << "double: " << d << std::endl;
}

void Convert::put_double(const double &d)
{
	double dint = 0;
	double dfract = std::modf(d, &dint);
	if (dfract == 0.0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

const char *Convert::InvalidValueException::what() const throw()
{
	return ("Invalid value.");
}

const char *Convert::OverflowIntException::what() const throw()
{
	return ("Overflow detected in int-type.");
}

const char *Convert::OverflowFloatException::what() const throw()
{
	return ("Overflow detected in float-type.");
}

const char *Convert::OverflowDoubleException::what() const throw()
{
	return ("Overflow detected in double-type.");
}


