/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:10:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 11:53:53 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	setType("WrongCat");
	std::cout << C_PURPLE << "WrongCat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << C_PURPLE << "WrongCat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
}
	
WrongCat::~WrongCat(void)
{
	std::cout << C_PURPLE << "WrongCat" << C_NONE << " : ";
	std::cout << "This old creature is purring on your lap...\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	setType(other.getType());
	return (*this);
}

void		WrongCat::makeSound(void) const
{
	std::cout << C_PURPLE << "WrongCat" << C_NONE << " : ";
	std::cout << "YAONG~\n";
}