/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:03:59 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:38:18 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "This little creature is trying to lick your face!\n";
	_brain = new Brain;
}

Dog::Dog(const Dog &other)
{
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "This little creature is trying to lick your face!\n";
	_brain = new Brain;
	*this = other;
}
	
Dog::~Dog(void)
{
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "Your old friend is trying to lick your face...\n";
	delete _brain;
}

Dog	&Dog::operator=(const Animal &other)
{
	*this = dynamic_cast<const Dog &>(other);
	return (*this);
}


Dog	&Dog::operator=(const Dog &other)
{
	setType(other.getType());
	*_brain = *(other.getBrain());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << C_BLUE << "Dog" << C_NONE << " : ";
	std::cout << "WALL! WALL!\n";
}

void	Dog::setBrain(std::string idea)
{
	for (int i = 0; i < 100; ++i)
		_brain->setIdea(i, idea);
}

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}

void	Dog::printBrain(void) const
{
	for (int i = 0; i < 2; ++i)
		std::cout << _brain->getIdea(i) << "\n";
	std::cout << "\n";
}