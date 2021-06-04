/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:25:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 16:24:07 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"

class Squad : public ISquad
{
    private:
		int count;
		ISpaceMarine **units;
    public:
        Squad();
        ~Squad();
        Squad(const Squad &src);
        Squad& operator = (const Squad &src);

		int getCount() const;
		ISpaceMarine* getUnit(int n) const;
		int push(ISpaceMarine *marine);
};

#endif