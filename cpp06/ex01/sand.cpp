/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:27:21 by lbagg             #+#    #+#             */
/*   Updated: 2021/06/07 15:11:38 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize(void) {
	srand(time(NULL));
	std::string array = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int size = array.length();
	char* raw = new char[20];

	for (int i = 0; i < 8; i++)
		raw[i] = array[rand() % size];
	*reinterpret_cast<int*>(raw + 8) = rand() % 1000;
	for (int i = 12; i < 20; i++)
		raw[i] = array[rand() % size];
	return raw;
}

Data * deserialize(void * raw) {
	Data* data = new Data;
	data->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	data->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return data;
}

int main() {

	void *raw = serialize();
	Data *data = deserialize(raw);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	std::cout << "n: " << data->n << std::endl;

	return 0;
}