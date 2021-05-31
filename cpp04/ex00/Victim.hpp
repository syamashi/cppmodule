/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:31:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/29 17:15:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
	public:
		Victim();
		Victim(const std::string &name);
		Victim(const Victim &src);
		~Victim();
		std::string get_name() const;
		virtual void getPolymorphed() const;
		Victim& operator=(const Victim &src);
	protected:
		std::string name;
	private:
};

std::ostream &operator<<(std::ostream &out, const Victim &src);

#endif
