/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:50:58 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 22:41:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("CT-00_clap_name"), _name("CT-00")
{
	setHP(FRAG_HP);
	setEP(SCAV_EP);
	setDP(FRAG_DP);
	setHP_MAX(FRAG_HP_MAX);
	std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " is upgraded!\n";
	printInfo();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	setHP(FRAG_HP);
	setEP(SCAV_EP);
	setDP(FRAG_DP);
	setHP_MAX(FRAG_HP_MAX);
	setDiaName(name);
	std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " is upgraded!\n";
	printInfo();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
	setDiaName(other.getDiaName());
	std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " is upgraded!\n";
	printInfo();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
	std::cout << _name << " has been destroyed!\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	setName(other.getName());
	setHP(other.getHP());
	setEP(other.getEP());
	setDP(other.getDP());
	setHP_MAX(other.getHP_MAX());
	setDiaName(other.getDiaName());
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (getEP() > 0 && getHP() > 0) {
	std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
	std::cout << "I am " << getName() << " as ClapTrap and ";
	std::cout << _name << " as DiamondTrap!\n";
	}
	if (getEP() == 0 || getHP() == 0) {
		std::cout << COLOR_BLUE << "DiamondTrap"  << COLOR_NONE << " : ";
		std::cout << _name << " can't move anymore...\n";
	}
	printInfo();
}

std::string	DiamondTrap::getDiaName(void) const
{
	return (_name);
}

void	DiamondTrap::setDiaName(std::string name)
{
	setName(name + "_clap_name");
	_name = name;
}