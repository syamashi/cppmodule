/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:10:07 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/03 16:49:44 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
    public:
        Form();
        ~Form();
        Form(const Form &src);
		Form(const std::string &name, const int &sign_grade, const int &exec_grade);
        Form& operator = (const Form &src);

		const std::string &getName() const;
		bool getSigned() const;
		const int &getSignG() const;
		const int &getExecG() const;

		void beSigned(Bureaucrat &_bt);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &src);

#endif