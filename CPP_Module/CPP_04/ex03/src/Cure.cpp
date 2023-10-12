/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:29:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 12:30:21 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
}

Cure::~Cure(void)
{
}

Cure		&Cure::operator=(const AMateria &other)
{
	*this = dynamic_cast<const Cure &>(other);
	return (*this);
}

Cure		&Cure::operator=(const Cure &other)
{
	if (_type != other.getType())
		std::cout << "Something Wrong!\n";
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	AMateria	*new_Cure = new Cure;

	return (new_Cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}