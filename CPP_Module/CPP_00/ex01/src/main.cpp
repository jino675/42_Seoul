/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:57:57 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/29 19:00:26 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	input;

	while (true) {
		std::cout << "=========================================\n\n";
		std::cout << "Select Menu - (ADD) or (SEARCH) or (EXIT)\n--> ";
		std::getline(std::cin, input);

		if (input == "ADD" || input == "add")
			pb.add();
		else if (input == "SEARCH" || input == "search")
			pb.search();
		else if (input == "EXIT" || input == "exit")
			break ;
		else if (std::cin.eof() == false)
			std::cout << "Wrong input!\n\n";
		else
			break ;
	}
	return (0);
}