/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:17:58 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/21 15:39:44 by syamashi         ###   ########.fr       */
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
	return (ret.c_str());
}

void *serialize(void)
{
	void *ret = reinterpret_cast<void*>(new char[52]);
	Data d;
	std::string *ps1;
	int	*pn;
	std::string *ps2;

	d.s1 = str_rand();
	d.n = rand() % 10000;
	d.s2 = str_rand();

	ps1 = reinterpret_cast<std::string*>(ret);
	*ps1 = d.s1;
	std::cout << "ps1: " << ps1 << std::endl;
	++ps1;
	pn = reinterpret_cast<int*>(ps1);
	std::cout << "pn: " << pn << std::endl;
	*pn = d.n;
	++pn;
	ps2 = reinterpret_cast<std::string*>(pn);
	std::cout << "ps2: " << ps2 << std::endl;
	*ps2 = d.s2;
	return (ret);
}

Data * deserialize(void * raw)
{
	Data *ret = new Data;
	ret = reinterpret_cast<Data*>(raw);
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
