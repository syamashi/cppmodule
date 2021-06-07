/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:47:10 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 17:24:14 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base & p)
{
	identify_from_pointer(&p);
}

Base * generate(void)
{
	Base *ret;

	switch (rand() % 3)
	{
	case 0:
		ret = new A;
		break;
	case 1:
		ret = new B;
		break;
	case 2:
		ret = new C;
		break;
	}
	return (ret);
}

int main()
{
	srand(time(NULL));
	try
	{
		Base *base = generate();
		Base &ref = *base;

		std::cout << "----- identify_from_pointer(base) -----" << std::endl;
		identify_from_pointer(base);
		std::cout << "----- identify_from_reference(ref) -----" << std::endl;
		identify_from_reference(ref);
		delete base;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
