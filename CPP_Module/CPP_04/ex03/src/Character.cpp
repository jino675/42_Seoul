/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:53:28 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 14:22:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Scavenger	scavenger;

Character::Character(void) : _name("???")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	*this = other;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

Character	&Character::operator=(const Character &other)
{
	_name = other.getName();
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
	}

	return (*this);
}

const std::string	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (_inventory[idx] != NULL) {
		scavenger.eat(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (_inventory[idx] != NULL) {
		_inventory[idx]->use(target);
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}