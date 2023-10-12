/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:46:55 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:46:58 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : 
name(name), weapon(NULL)
{
}

void	HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout << name << " attack with their " << (*weapon).getType() << "\n";
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}
