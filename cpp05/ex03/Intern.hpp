/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:32:06 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/04 15:27:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern& operator = (const Intern &src);
		Form *makeForm(const std::string &name, const std::string &target);

		Form *InternShrubbery(const std::string &target);
		Form *InternRobotomy(const std::string &target);
		Form *InternPresidential(const std::string &target);

		class NotMatchNameException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
