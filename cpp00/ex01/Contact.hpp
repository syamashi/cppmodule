/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:22 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 19:02:52 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
		std::string info[11];
	public:
        Contact();
        ~Contact();
        Contact(const Contact &src);
        Contact& operator = (const Contact &src);

		void set_info(int &column, std::string &input);
		void get_info_top(int &index) const;
		void get_info_index() const;
};

#endif