/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:17:58 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 16:43:09 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void pout(const std::string &mes)
{
	std::cout << " ------ " << mes << " ------ " << std::endl;
}

void *serialize(void)
{
	char *ret = new char[21];
	std::string bases = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
	int bases_len = bases.length();
	for (int i = 0; i < 8; i++)
		ret[i] = bases[rand() % bases_len];
	*reinterpret_cast<int*>(ret + 8) = rand() % 10000;
	for (int i = 12; i < 20; i++)
		ret[i] = bases[rand() % bases_len];
	ret[20] = '\0';
	return (ret);
}

Data * deserialize(void * raw)
{
	Data *ret = new Data;
	ret->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	ret->n = *reinterpret_cast<int*>(reinterpret_cast<char*>(raw) + 8);
	ret->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return (ret);
}

int main()
{
	srand(time(NULL));
	try
	{
		void * raw = serialize();
		Data * dat = deserialize(raw);
		std::cout << dat->s1 << " " << dat->n << " " << dat->s2 << std::endl;
		delete dat;
		delete reinterpret_cast<char*>(raw);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
