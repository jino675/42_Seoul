/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:47:16 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 21:38:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Scavenger.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string	_name;
	AMateria	*_inventory[4];

public:
	Character(void);
	Character(std::string name);
	Character(const Character &other);
	virtual ~Character(void);
	Character	&operator=(const Character &other);

	virtual const std::string	&getName() const;
	virtual void	equip(AMateria *m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter &target);
};

#endif