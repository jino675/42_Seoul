/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:16:10 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/25 14:39:23 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type((std::string)"hands")
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

std::string	&Weapon::getType(void)
{
	return (type);
}

void		Weapon::setType(std::string new_type)
{
	type = new_type;
}
