/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:48:12 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 19:26:10 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

void memoryLeak()
{
	try
	{
		std::string* panther = new std::string("String panther");
		std::cout << *panther << std::endl;
		delete panther;
	}
	catch(std::bad_alloc){
		std::cout << "bad_alloc" << std::endl;
		std::exit(1);
	}
}

int main()
{
	memoryLeak();
	return (0);
}