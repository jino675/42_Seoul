/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:43:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/29 21:10:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name(std::string("Somebody"))
{
	std::cout << name << " became a zombie!\n";
}

Zombie::~Zombie(void)
{
	std::cout << name << " finally died for real!\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string &new_name)
{
	name = new_name;
	std::cout << "Its name was " << name << "!\n";
}