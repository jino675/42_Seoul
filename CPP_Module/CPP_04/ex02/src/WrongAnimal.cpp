/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:52:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 11:52:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) :
_type("WrongAnimal")
{
	std::cout << C_YELLOW << "WrongAnimal" << C_NONE << " : ";
	std::cout << "A new life is born!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << C_YELLOW << "WrongAnimal" << C_NONE << " : ";
	std::cout << "A new life is born!\n";
}
	
WrongAnimal::~WrongAnimal(void)
{
	std::cout << C_YELLOW << "WrongAnimal" << C_NONE << " : ";
	std::cout << "A life is dead!\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	setType(other.getType());
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void		WrongAnimal::setType(std::string type)
{
	_type = type;
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << C_YELLOW << "WrongAnimal" << C_NONE << " : ";
	std::cout << "......\n";
}