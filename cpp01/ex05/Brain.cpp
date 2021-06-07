/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:45:42 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:09:27 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::~Brain()
{
	std::cout << "[~Brain] died" << std::endl;
}

std::string Brain::identify()
{
	std::stringstream	sst;
	sst << this;
	return (sst.str());
}
