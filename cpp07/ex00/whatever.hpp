/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:01:32 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 21:01:49 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

template <typename T>
T const min(T const &a, T const &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

#endif