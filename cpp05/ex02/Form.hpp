/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:10:07 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 17:00:30 by syamashi         ###   ########.fr       */
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
		const std::string _target;
    public:
        Form();
        virtual ~Form();
        Form(const Form &src);
		Form(const std::string &name, const int &sign_grade, const int &exec_grade);
		Form(const std::string &name, const int &sign_grade, const int &exec_grade, const std::string &target);
        Form& operator = (const Form &src);

		const std::string &getName() const;
		bool getSigned() const;
		const int &getSignG() const;
		const int &getExecG() const;
		const std::string &getTarget() const;

		void beSigned(Bureaucrat &_bt);

		virtual void execute(Bureaucrat const & executor) const = 0;
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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, const Form &src);

#endif