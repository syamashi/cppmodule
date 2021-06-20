/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:43:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 11:05:11 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Kid.hpp"

Kid::Kid(std::string name) : Victim(name)
{
	std::cout << "shabettaaaaaaaaaaaaa!!!!" << std::endl;
}

Kid::Kid(const Kid &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Kid::~Kid()
{
	std::cout << "happy seeeeeeeeeeet..." << std::endl;
}

void	Kid::getPolymorphed() const
{
	//NAME has been turned into a pink pony!
	std::cout << this->name << " has been turned into a hamburger!" << std::endl;
}

Kid& Kid::operator=(Kid const &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->name = src.name;
    return (*this);
}
