/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavenger.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:42:04 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 21:45:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVENGER_HPP
# define SCAVENGER_HPP

# include "AMateria.hpp"

class Scavenger {
private:
	AMateria	**_inventory;
	int			_size;
	int			_top;

public:
	Scavenger(void);
	Scavenger(const Scavenger &other);
	~Scavenger(void);
	Scavenger	&operator=(const Scavenger &other);

	void	eat(AMateria *m);
};

#endif