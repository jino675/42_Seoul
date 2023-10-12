/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavenger.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:46:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:39:16 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scavenger.hpp"

Scavenger::Scavenger(void) : _size(10), _top(-1)
{
	_inventory = new AMateria*[_size];
	for (int i = 0; i < _size; ++i)
		_inventory[i] = NULL;
}

Scavenger::Scavenger(const Scavenger &other)
{
	*this = other;
}

Scavenger::~Scavenger(void)
{
	for (int i = 0; _inventory[i] != NULL; ++i)
		delete _inventory[i];
	delete[] _inventory;
}

Scavenger	&Scavenger::operator=(const Scavenger &other)
{
	if (other._size == 0)
		return (*this);
	else
		return (*this);
}

void	Scavenger::eat(AMateria *m)
{
	if (_inventory[_size - 1] != NULL) {
		AMateria	**temp = new AMateria*[_size * 2];
		for (int i = 0; i < _size * 2; ++i) {
			if (i < _size)
				temp[i] = _inventory[i];
			else
				temp[i] = NULL;
		}
		delete[] _inventory;
		_size *= 2;
		_inventory = temp;
	}
	_inventory[++_top] = m;
}
