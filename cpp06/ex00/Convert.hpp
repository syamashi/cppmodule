/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:48:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/06 00:33:18 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>

#define TYPE_INFP 0
#define TYPE_INFM 1
#define TYPE_NAN 2
#define TYPE_C 3
#define TYPE_I 4
#define TYPE_F 5
#define TYPE_D 6
#define FAIL 7

class Convert
{
    private:
		const std::string _input;
		int _type;
		char _c;
		int _i;
		float _f;
		double _d;

    public:
        Convert();
        ~Convert();
        Convert(const Convert &src);
		Convert(const std::string &input);
        Convert& operator = (const Convert &src);

		void put_char(const std::string &c);
		void put_char(const char &c);
		void put_int(const std::string &i);
		void put_int(const int &i);
		void put_float(const std::string &f);
		void put_float(const float &fint, const float &ffract);
		void put_double(const std::string &d);
		void put_double(const double &dint, const double &dfract);

		int get_type();
		void ft_limits();
		void ft_stoc();
		void ft_stoi();
		void ft_stof();
		void ft_stod();

		class InvalidValueException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OverflowIntException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OverflowFloatException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OverflowDoubleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
