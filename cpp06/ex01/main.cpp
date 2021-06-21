/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:17:58 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/21 16:25:22 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>

#pragma pack(1)
struct Data {
	std::string s1;
	int n;
	std::string s2;
};
#pragma pack()

void pout(const std::string &mes)
{
	std::cout << " ------ " << mes << " ------ " << std::endl;
}

std::string str_rand(void)
{
	std::string ret = "";
	std::string bases = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
	int bases_len = bases.length();
	for (int i = 0; i < 8; ++i)
		ret += bases[rand() % bases_len];
	return (ret);
}

void *serialize(void)
{
	Data *ret = new Data;
	
	ret->s1 = str_rand();
	ret->n = rand() % 10000;
	ret->s2 = str_rand();

	std::cout << "&ret->s1: " << &ret->s1 << std::endl;
	std::cout << "&ret->n : " << &ret->n  << std::endl;
	std::cout << "&ret->s2: " << &ret->s2 << std::endl;
	return (ret);
}

Data * deserialize(void * raw)
{
	Data *ret = new Data;
	ret = reinterpret_cast<Data*>(raw);
	std::cout << ret->s1 << " " << ret->n << " " << ret->s2 << std::endl;
	return (ret);
}

int main()
{
	srand(time(NULL));
	try
	{
		void * raw = serialize();

		Data * dat = deserialize(raw);
		return 0;
		std::cout << dat->s1 << " " << dat->n << " " << dat->s2 << std::endl;
		delete dat;
//		delete reinterpret_cast<char*>(raw);
		// delete *void is undefined command...
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(Data) << std::endl;
}
