/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:55:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 19:03:05 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : _depth(0)
{
	std::string blank = "";
	for (int i = 0; i < MAXLINE; i++)
		_contact[i].set_info(i, blank);
}

void Phonebook::addcmd()
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
	if (_depth >= MAXLINE)
	{
		std::cout << "[i] phonebook is full." << std::endl;
		return ;
	}
	bool filled = false;
	std::string input;
	for (int i = 0; i < 11; ++i)
	{
		std::cout << "[ADD] " << std::setfill(' ') << std::setw(15);
		std::cout << heads[i] << " < ";
		std::getline(std::cin, input);
		if (input.length())
		{
			filled = true;
			this->_contact[_depth].set_info(i, input);
		}
	}
	if (!filled)
	{
		std::cout << "[i] nothing inputs" << std::endl;
		return ;
	}
	std::cout << "[i] " << _depth << " index recorded" << std::endl;
	++_depth;
}

void	Phonebook::searchcmd()
{
	if (_depth == 0)
	{
		std::cout << "[i] phonebook is empty." << std::endl;
		return ;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|index     |first name|last name |nick name |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < _depth; ++i)
	{
		this->_contact[i].get_info_top(i);
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (1)
	{
		std::string input;
		std::cout << "[SEARCH] > ";
		std::getline(std::cin, input);
		if (input == "Q")
			break;
		bool non_num = false;
		int input_len = input.size();
		for (int i = 0; i < input_len; i++)
		{
			if (input[i] < '0' || input[i] > '9')
			{
				non_num = true;
				break;
			}
		}
		if (non_num || input_len == 0)
		{
			std::cout << "[USAGE] <0 ~ " << _depth - 1 << "> indexes can show you. 'Q' is exit." << std::endl;
			continue;
		}
		int num = 0;
		for (int i = 0; i < input_len; i++)
			num = num * 10 + input[i] - '0';
		if (num >= _depth)
			std::cout << "[USAGE] <0 ~ " << _depth - 1 << "> indexes can show you. 'Q' is exit." << std::endl;
		else
			this->_contact[num].get_info_index();
	}
}

void Phonebook::exitcmd()
{
	std::cout << "EXIT" << std::endl;
	exit(0);
}
