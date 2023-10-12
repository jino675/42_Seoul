/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:27:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:40:14 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAG_HP		100
# define FRAG_EP		100
# define FRAG_DP		30
# define FRAG_HP_MAX	100

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	virtual ~FragTrap(void);
	FragTrap	&operator=(const FragTrap &other);
	void		highFivesGuys(void);
};

#endif