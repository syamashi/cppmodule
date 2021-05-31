/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:33:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/30 11:51:29 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
    std::cout << "Default constructor called" << std::endl;
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title) : name(name), title(title)
{
	//NAME, TITLE, is born!
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}


Sorcerer::~Sorcerer()
{
	//NAME, TITLE, is dead. Consequences will never be the same!
	std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::get_name() const
{
	return (this->name);
}

std::string Sorcerer::get_title() const
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const &vct) const
{
	vct.getPolymorphed();
}

Sorcerer& Sorcerer::operator=(const Sorcerer &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->name = src.name;
	this->title = src.title;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &src)
{
	//I am NAME, TITLE, and I like ponies!
	out << "I am " << src.get_name() << ", " << src.get_title() << ", and I like ponies!" << std::endl;
	return (out);
}
