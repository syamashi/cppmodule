/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:11:32 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 18:39:04 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(Contact const &src)
{
    *this = src;
}

Contact::~Contact()
{
}

Contact& Contact::operator=(const Contact &src)
{
    if (this == &src)
        return (*this);
	for (int i = 0; i < 11; i++)
		this->info[i] = src.info[i];
    return (*this);
}

void Contact::set_info(int &column, std::string &input)
{
	this->info[column] = input;
}

void Contact::get_info_top(int &index) const
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << index;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "|";
		if (this->info[i].size() <= 10)
			std::cout << std::setfill(' ') << std::setw(10) << this->info[i];
		else
		{
			for (int j = 0; j < 9; ++j)
				std::cout << this->info[i][j];
			std::cout << ".";
		}
	}
	std::cout << "|" << std::endl;
}

void Contact::get_info_index() const
{
	std::string heads[11] = {
		"first_name",
		"last_name",
		"nickname",
		"login",
		"postal_address",
		"email_address",
		"phone_number",
		"birthday_date",
		"favorite_meal",
		"underwear_color",
		"darkest_secret"
	};
	for (int i = 0; i < 11; ++i)
	{
		std::cout << std::setfill(' ') << std::setw(15) << heads[i] << ": " << this->info[i] << std::endl;
	}
}
