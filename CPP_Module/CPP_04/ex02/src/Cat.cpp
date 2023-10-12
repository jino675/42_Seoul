/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:10:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:38:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
	_brain = new Brain;
}

Cat::Cat(const Cat &other)
{
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
	_brain = new Brain;
	*this = other;
}
	
Cat::~Cat(void)
{
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "Your old friend is purring on your lap...\n";
	delete _brain;
}

Cat	&Cat::operator=(const Animal &other)
{
	*this = dynamic_cast<const Cat &>(other);
	return (*this);
}

Cat	&Cat::operator=(const Cat &other)
{
	setType(other.getType());
	*_brain = *(other.getBrain());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "YAONG~\n";
}

void	Cat::setBrain(std::string idea)
{
	for (int i = 0; i < 100; ++i)
		_brain->setIdea(i, idea);
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}

void	Cat::printBrain(void) const
{
	for (int i = 0; i < 2; ++i)
		std::cout << _brain->getIdea(i) << "\n";
	std::cout << "\n";
}