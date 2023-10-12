/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:03:59 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/07 22:13:45 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "This little creature is trying to lick your face!\n";
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "This little creature is trying to lick your face!\n";
}
	
Dog::~Dog(void)
{
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "Your old friend is trying to lick your face...\n";
}

Dog	&Dog::operator=(const Animal &other)
{
	*this = dynamic_cast<const Dog &>(other);
	return (*this);
}

Dog	&Dog::operator=(const Dog &other)
{
	setType(other.getType());
	return (*this);
}

void		Dog::makeSound(void) const
{
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "WALL! WALL!\n";
}