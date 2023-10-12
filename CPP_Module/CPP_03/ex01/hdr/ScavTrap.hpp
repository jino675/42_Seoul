/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:27:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:23:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAV_HP		100
# define SCAV_EP		50
# define SCAV_DP		20
# define SCAV_HP_MAX	100

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap(void);
	ScavTrap	&operator=(const ScavTrap &other);

	virtual void	attack(const std::string &target);
	void			guardGate(void);
};

#endif