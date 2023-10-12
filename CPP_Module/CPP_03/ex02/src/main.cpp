/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:40:09 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:34:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	FragTrap	b("CT-99");
	FragTrap	c(b);
	FragTrap	d;

	d = c;
	
	std::string	enemy("Enemy-00");
	d.attack(enemy);

	b.setName("CT-01");
	c.setName("CT-02");
	d.setName("CT-03");

	b.takeDamage(40);
	c.takeDamage(100);
	d.takeDamage(120);
	
	b.beRepaired(30);
	b.beRepaired(50);
	c.beRepaired(30);

	b.highFivesGuys();
	c.highFivesGuys();
	
	return (0);
}