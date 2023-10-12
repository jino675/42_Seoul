/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:44:11 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:45:03 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : 
name(name), weapon(weapon)
{	
}

void	HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << "\n";
}