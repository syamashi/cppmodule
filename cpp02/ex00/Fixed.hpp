/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:43:58 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/05 00:07:11 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	rawbits;
		static	int const bits;

	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();
		Fixed&	operator=(Fixed const &src);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif