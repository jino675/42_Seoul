/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/26 17:25:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	std::string	filename, s1, s2;

	if (ac != 4) {
		std::cout << "Wrong argument!\n";
		exit(1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	Sed(filename, s1, s2);

	return (0);
}
