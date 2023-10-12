/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:40:09 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:54:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a;
	DiamondTrap	b("CT-99");
	DiamondTrap	c(b);
	DiamondTrap	d;

	d = c;
	
	std::string	enemy("Enemy-00");
	d.attack(enemy);

	b.setDiaName("CT-01");
	c.setDiaName("CT-02");
	d.setDiaName("CT-03");

	b.takeDamage(40);
	c.takeDamage(100);
	d.takeDamage(120);
	
	b.beRepaired(30);
	b.beRepaired(50);
	c.beRepaired(30);

	b.guardGate();
	c.guardGate();
	
	b.highFivesGuys();
	c.highFivesGuys();
	
	b.whoAmI();
	c.whoAmI();
	
	return (0);
}