/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:45:42 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 18:29:32 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
	std::cout << "[~Brain] died" << std::endl;
}

std::string Brain::identify() const
{
	std::stringstream	sst;
	sst << this;

	std::string ret = sst.str();
	int ret_len = ret.length();
	for(int i = 2; i < ret_len; i++)
		ret[i] = std::toupper(ret[i]);
	return (ret);
}
