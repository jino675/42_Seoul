/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:10:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 16:55:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "This little creature is hissing at you!\n";
}
	
Cat::~Cat(void)
{
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "Your old friend is purring on your lap...\n";
}

Cat	&Cat::operator=(const Animal &other)
{
	*this = dynamic_cast<const Cat &>(other);
	return (*this);
}

Cat	&Cat::operator=(const Cat &other)
{
	setType(other.getType());
	return (*this);
}

void		Cat::makeSound(void) const
{
	std::cout << C_PURPLE << "Cat" << C_NONE << " : ";
	std::cout << "YAONG~\n";
}