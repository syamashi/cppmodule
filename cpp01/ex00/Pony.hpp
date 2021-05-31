/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:53:18 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/21 22:27:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>
void ponyOnTheHeap();
void ponyOnTheStack();
class Pony
{
	public:
		Pony(std::string s);
		void	ponyout();
	private:
		std::string str;
};

#endif