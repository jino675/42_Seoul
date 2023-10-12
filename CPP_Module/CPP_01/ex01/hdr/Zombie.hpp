/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:56:10 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/29 21:08:26 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

private:
	std::string	name;

public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	set_name(std::string &new_name);
};

#endif