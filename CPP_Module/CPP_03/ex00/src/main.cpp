/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:40:09 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:34:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("CT-99");
	ClapTrap	c(b);
	ClapTrap	d;

	d = c;
	
	std::string	enemy("Enemy-00");
	d.attack(enemy);

	b.setName("CT-01");
	c.setName("CT-02");
	d.setName("CT-03");

	b.takeDamage(4);
	c.takeDamage(10);
	d.takeDamage(12);

	b.beRepaired(3);
	b.beRepaired(5);
	c.beRepaired(3);

	return (0);
}