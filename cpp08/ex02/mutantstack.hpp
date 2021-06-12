/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:10:22 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/12 18:32:59 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack<T>& operator = (const MutantStack<T> &src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {}


template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T> &src)
{
	this->c = src.c;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){ return (this->c.begin());}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){ return (this->c.end());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return (this->c.begin());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return (this->c.end());}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){ return (this->c.rbegin());}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){ return (this->c.rend());}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const { return (this->c.rbegin());}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const { return (this->c.rend());}

#endif