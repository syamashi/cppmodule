/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:42:41 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 09:59:27 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template<class T>
class Array
{
    private:
		T* data;
		int size;
    public:
        Array();
        ~Array();
        Array(const Array &src);
        Array& operator = (const Array &src);
};

#endif