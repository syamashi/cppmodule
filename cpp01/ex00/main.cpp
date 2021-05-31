/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:57:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/21 22:27:26 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int main()
{
	std::cout << "-----Heap pony start-----" << std::endl;
	ponyOnTheHeap();
	std::cout << "-----Stack pony start-----" << std::endl;
	ponyOnTheStack();
	return (0);
}
