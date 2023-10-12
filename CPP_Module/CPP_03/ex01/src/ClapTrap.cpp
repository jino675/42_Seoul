/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:55:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:52:50 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
_name("CT-00"), _HP(CLAP_HP), _EP(CLAP_EP), _DP(CLAP_DP), _HP_MAX(CLAP_HP_MAX)
{
	std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " has been created!\n";
	printInfo();
}

ClapTrap::ClapTrap(std::string name) :
_name(name), _HP(CLAP_HP), _EP(CLAP_EP), _DP(CLAP_DP), _HP_MAX(CLAP_HP_MAX)
{
	std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " has been created!\n";
	printInfo();
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " has been created!\n";
	printInfo();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " has been destroyed!\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	setName(other.getName());
	setHP(other.getHP());
	setEP(other.getEP());
	setDP(other.getDP());
	setHP_MAX(other.getHP_MAX());

	return (*this);
}

void		ClapTrap::attack(const std::string &target)
{
	if (_EP > 0 && _HP > 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " attacks " << target << ", causing " << _DP << " points of damage!\n";
		--_EP;
	}
	if  (_EP == 0 || _HP == 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " can't move anymore...\n";
	}
	printInfo();
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (_EP > 0 && _HP > 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " takes " << amount << " points of damage!\n";
		_HP -= amount;
		if (_HP < 0)
			_HP = 0;
	}
	if  (_EP == 0 || _HP == 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " can't move anymore...\n";
	}
	printInfo();
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (_EP > 0 && _HP > 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " is repaired by " << amount << " HP!\n";
		_HP += amount;
		if (_HP > _HP_MAX)
			_HP = _HP_MAX;
		--_EP;
	}
	if  (_EP == 0 || _HP == 0) {
		std::cout << COLOR_CYAN << "ClapTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " can't move anymore...\n";
	}
	printInfo();
}

void		ClapTrap::printInfo(void)
{
	std::cout << COLOR_YELLOW << "[ HP : " << _HP << ", EP : " << _EP << \
		", DP : " << _DP << ", HP_MAX : " << _HP_MAX <<  " ]\n\n" << COLOR_NONE;
}

void	ClapTrap::setName(const std::string name)
{
	_name = name;
}

void	ClapTrap::setHP(const int HP)
{
	_HP = HP;
}

void	ClapTrap::setEP(const int EP)
{
	_EP = EP;
}

void	ClapTrap::setDP(const int DP)
{
	_DP = DP;
}

void	ClapTrap::setHP_MAX(const int HP_MAX)
{
	_HP_MAX = HP_MAX;
}

std::string ClapTrap::getName(void) const
{
	return (_name);	
}

int ClapTrap::getHP(void) const
{
	return (_HP);
}

int	ClapTrap::getEP(void) const
{
	return (_EP);
}

int	ClapTrap::getDP(void) const
{
	return (_DP);
}

int ClapTrap::getHP_MAX(void) const
{
	return (_HP_MAX);
}
