/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:34:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:57:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	setHP(SCAV_HP);
	setEP(SCAV_EP);
	setDP(SCAV_DP);
	setHP_MAX(SCAV_HP_MAX);
	std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHP(SCAV_HP);
	setEP(SCAV_EP);
	setDP(SCAV_DP);
	setHP_MAX(SCAV_HP_MAX);
	std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " has been destroyed!\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	setName(other.getName());
	setHP(other.getHP());
	setEP(other.getEP());
	setDP(other.getDP());
	setHP_MAX(other.getHP_MAX());
	
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (getEP() > 0 && getHP() > 0) {
		std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " attacks " << target << ", causing " << getDP() << " points of damage!\n";
		setEP(getEP() - 1);
	}
	if (getEP() == 0 || getHP() == 0) {
		std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " can't move anymore...\n";
	}
	printInfo();
}

void	ScavTrap::guardGate(void)
{
	if (getEP() > 0 && getHP() > 0) {
		std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " is now in Gate Keeper mode.\n";
	}
	if (getEP() == 0 || getHP() == 0) {
		std::cout << COLOR_GREEN << "ScavTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " can't move anymore...\n";
	}
	printInfo();
}