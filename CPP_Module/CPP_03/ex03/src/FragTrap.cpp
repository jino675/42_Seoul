/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:34:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:56:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	setHP(FRAG_HP);
	setEP(FRAG_EP);
	setDP(FRAG_DP);
	setHP_MAX(FRAG_HP_MAX);
	std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHP(FRAG_HP);
	setEP(FRAG_EP);
	setDP(FRAG_DP);
	setHP_MAX(FRAG_HP_MAX);
	std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " is upgraded!\n";
	printInfo();
}

FragTrap::~FragTrap(void)
{
	std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
	std::cout << getName() << " has been destroyed!\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	setName(other.getName());
	setHP(other.getHP());
	setEP(other.getEP());
	setDP(other.getDP());
	setHP_MAX(other.getHP_MAX());
	
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (getEP() > 0 && getHP() > 0) {
		std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " is trying to high-five!\n";
	}
	if (getEP() == 0 || getHP() == 0) {
		std::cout << COLOR_PURPLE << "FragTrap"  << COLOR_NONE << " : ";
		std::cout << getName() << " can't move anymore...\n";
	}
	printInfo();
}