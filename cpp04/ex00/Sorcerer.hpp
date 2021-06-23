/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:31:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/22 12:49:05 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(const std::string &name, const std::string &title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer();
		std::string get_name() const;
		std::string get_title() const;

		void polymorph(Victim const &vct) const;
		Sorcerer& operator=(const Sorcerer &src);
	private:
		Sorcerer();
		std::string name;
		std::string title;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &src);

#endif
