/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/28 13:33:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		lady;

	if (ac != 2)
	{
		std::cout << "Wrong input!\n";
		return (1);
	}
	lady.print_above((std::string)av[1]);

	return (0);
}
