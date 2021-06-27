/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:40:33 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/27 18:39:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
    private:
		unsigned int _N;
		unsigned int _size;
		std::vector<int> _vec;
    public:
        Span();
        ~Span();
        Span(const Span &src);
        Span(int N);
        Span& operator = (const Span &src);

		void addNumber(const int &n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		class FilledException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughSizeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif