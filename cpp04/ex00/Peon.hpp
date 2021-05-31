/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:42:21 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/29 17:08:35 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon();
		Peon(std::string name);
		Peon(Peon const &src);
		virtual ~Peon();

		Peon& operator=(const Peon &src);
		void getPolymorphed() const;
	private:
};

#endif