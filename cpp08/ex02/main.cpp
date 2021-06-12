/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:06:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/12 18:56:55 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
void pout(T &mes)
{
	std::cout << std::endl << "----- " << mes << " -----" << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	pout(".push(5)");
	mstack.push(5);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	pout(".push(17)");
	mstack.push(17);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	pout(".pop()");
	mstack.pop();
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	pout(".push(3)");
	mstack.push(3);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	pout(".push(5)");
	mstack.push(5);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	pout(".push(737)");
	mstack.push(737);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	//[...]
	pout(".push(0)");
	mstack.push(0);
	std::cout << "mstack[" << mstack.size() - 1 << "]: " << mstack.top() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int cnt = -1;
	while (it != ite)
	{
		++cnt;
		std::cout << "*it[" << cnt << "]: " << *it << std::endl;
		++it;
	}

	pout("const_iterator");
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	++cit;
	--cit;
	cnt = -1;
	while (cit != cite)
	{
		++cnt;
		std::cout << "*cit[" << cnt << "]: " << *cit << std::endl;
		++cit;
	}

	pout("reverse_iterator");
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	cnt = -1;
	while (rit != rite)
	{
		++cnt;
		std::cout << "*rit[" << cnt << "]: " << *rit << std::endl;
		++rit;
	}

	pout("const_reverse_iterator");
	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	++crit;
	--crit;
	cnt = -1;
	while (crit != crite)
	{
		++cnt;
		std::cout << "*crit[" << cnt << "]: " << *crit << std::endl;
		++crit;
	}

	pout("s(mstack)");
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << "s[" << s.size() - 1 << "]: " << s.top() << std::endl;
		s.pop();
	}
	return (0);
}
