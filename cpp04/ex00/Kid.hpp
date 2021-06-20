/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:42:21 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 19:44:50 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KID_HPP
#define KID_HPP

#include <iostream>
#include "Victim.hpp"

class Kid : public Victim
{
	public:
		Kid();
		Kid(std::string name);
		Kid(Kid const &src);
		virtual ~Kid();

		Kid& operator=(const Kid &src);
		void getPolymorphed() const;
	private:
};

#endif