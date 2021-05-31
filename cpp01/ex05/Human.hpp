/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:25:36 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 10:46:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <sstream>
# include "Brain.hpp"

class Human
{
	public:
		Human();
		~Human();
		std::string identify();
		Brain&	getBrain();
	private:
		Brain*	br;
};

#endif
