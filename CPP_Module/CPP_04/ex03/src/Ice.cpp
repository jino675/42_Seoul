/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:19:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 12:10:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
}

Ice::~Ice(void)
{
}

Ice		&Ice::operator=(const AMateria &other)
{
	*this = dynamic_cast<const Ice &>(other);
	return (*this);
}

Ice		&Ice::operator=(const Ice &other)
{
	if (_type != other.getType())
		std::cout << "Something Wrong!\n";
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria	*new_ice = new Ice;

	return (new_ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}