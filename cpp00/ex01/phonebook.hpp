/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:55:43 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 16:53:51 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define PHONEBOOK "phonebook > "
# define MAXLINE 8

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Phonebook
{
	private:
		int	_depth;
		Contact	_contact[MAXLINE];
	public:
		Phonebook();
		void	addcmd();
		void	searchcmd();
		void	exitcmd();
};

#endif