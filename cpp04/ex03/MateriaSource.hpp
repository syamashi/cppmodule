/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:49:08 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/01 15:42:31 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
		AMateria *_memory[4];
		int	_count;
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource& operator = (const MateriaSource &src);

		std::string const &getMemtype(int idx) const;
		int const &getCount() const;
		bool isBlank(int idx) const;

		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

std::ostream& operator<<(std::ostream &out, MateriaSource const &src);

#endif