/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:47:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 12:12:16 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Nothing")
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria::~AMateria(void)
{
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (other.getType() == "I didn't wanna to this...")
		return (*this);
	else
		return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	if (target.getName() == "I didn't wanna to this...")
		return ;
}