/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:12:19 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/09 15:32:58 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("value does not found");
		};
};


template<typename T>
typename T::iterator easyfind(T &t, int n)
{
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw (NotFoundException());
	return (it);
}

#endif