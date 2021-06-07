/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:44:22 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:17:55 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	puterror(std::string str)
{
	std::cout << str << std::endl;
	std::exit(1);
}

void	fileerror(std::string filename)
{
	std::cout << "[e]" << filename << " does not exist." << std::endl;
	std::exit(1);
}

int main(int argc, char *argv[]) // (./replace, filename, str1, str2)
{
	std::string	filename;
	std::string	str1;
	std::string str2;
	if (argc != 4)
		puterror("[e]argc != 4 .");
	filename = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	if (str1 == "")
		puterror("[e]first string blank.");
	std::ifstream fin(filename);
	if (!fin)
		fileerror(filename);
	std::ofstream fout(filename + ".replace");
	if (!fout)
	{
		fin.close();
		puterror("failed to create output.replace.");
	}

	std::string	line;
	while (std::getline(fin, line) && !fin.eof())
	{
		std::string::size_type	pos = line.find(str1);
		while (pos != std::string::npos)
		{
			line.replace(pos, str1.length(), str2);
			pos = line.find(str1, pos + str1.length());
		}
		fout << line << std::endl;
	}
	std::string::size_type	pos = line.find(str1);
	while (pos != std::string::npos)
	{
		line.replace(pos, str1.length(), str2);
		pos = line.find(str1, pos + str1.length());
	}
	fout << line;
	fin.close();
	fout.close();
	return (0);
}
