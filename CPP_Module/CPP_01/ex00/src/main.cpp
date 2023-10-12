/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:15:43 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::string	zombie_name;
	Zombie		*my_zombie;

	zombie_name = "James";
	
	my_zombie = newZombie(zombie_name);
	if (my_zombie == NULL) {
		std::cout << "memory allocation error!\n";
		return (1);
	}
	my_zombie->announce();
	delete my_zombie;

	zombie_name = "Peter";
	randomChump(zombie_name);
	
	return (0);
}