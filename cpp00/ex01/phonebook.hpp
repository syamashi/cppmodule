/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:55:43 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/21 17:36:26 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define PHONEBOOK "phonebook > "
# define MAXLINE 8

# include <iostream>
# include <iomanip>
# include <string>

class Phonebook
{
	public:
		Phonebook();
		void	addcmd();
		void	searchcmd();
		void	exitcmd();
	private:
		enum Inputs {
			FIRST_NAME,
			LAST_NAME,
			NICKNAME,
			LOGIN,
			POSTAL_ADDRESS,
			EMAIL_ADDRESS,
			PHONE_NUMBER,
			BIRTHDAY_DATE,
			FAVORITE_MEAL,
			UNDERWEAR_COLOR,
			DARKEST_SECRET,
		};
		int	depth;
		std::string	info[MAXLINE][11];
		std::string heads[11] = {
			"first_name",
			"last_name",
			"nickname",
			"login",
			"postal_address",
			"email_address",
			"phone_number",
			"birthday_date",
			"favorite_meal",
			"underwear_color",
			"darkest_secret"
			};
};

#endif