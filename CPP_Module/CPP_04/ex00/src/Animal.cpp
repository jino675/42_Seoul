/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:52:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/07 22:13:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) :
_type("Animal")
{
	std::cout << C_YELLOW << "Animal" << C_NONE << " : ";
	std::cout << "A new life is born!\n";
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << C_YELLOW << "Animal" << C_NONE << " : ";
	std::cout << "A new life is born!\n";
}
	
Animal::~Animal(void)
{
	std::cout << C_YELLOW << "Animal" << C_NONE << " : ";
	std::cout << "A life is dead!\n";
}

Animal	&Animal::operator=(const Animal &other)
{
	setType(other.getType());
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void		Animal::setType(std::string type)
{
	_type = type;
}

void		Animal::makeSound(void) const
{
	std::cout << C_YELLOW << "Animal" << C_NONE << " : ";
	std::cout << "......\n";
}