/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:42:41 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:45:10 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon		*weapon;

public:
	HumanB(std::string	name);
	void	attack(void);
	void	setWeapon(Weapon &new_weapon);
};

#endif