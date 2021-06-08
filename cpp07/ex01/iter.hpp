/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:45:57 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 09:12:45 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *arr, int arr_len, void(func)(const T &))
{
	for (int i = 0; i < arr_len; i++)
		func(arr[i]);
}

#endif
