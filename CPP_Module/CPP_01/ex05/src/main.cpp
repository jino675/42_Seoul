/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/28 13:19:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		lady;
	std::string	input;

	while (true) {
		std::cin >> input;
		if (input == "QUIT")
			break ;
		lady.complain(input);
	}
	
	return (0);
}
