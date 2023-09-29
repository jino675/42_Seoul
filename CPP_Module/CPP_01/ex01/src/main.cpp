/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/24 19:41:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	std::string	zombie_name;
	Zombie		*my_zombies;

	zombie_name = "James";
	
	my_zombies = zombieHorde(10, zombie_name);
	for (int i = 0; i < 10; ++i)
		my_zombies[i].announce();
	
	delete[] my_zombies;

	return (1);
}