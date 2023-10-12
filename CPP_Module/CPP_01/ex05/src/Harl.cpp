/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:44:11 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 16:30:32 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger.\n";
	std::cout << "I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable!\n";
	std::cout << "I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	void		(Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i) {
		if (strs[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "I don't like you...\n\n";
}