/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:17:07 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 21:29:30 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &other);
	virtual ~Ice(void);
	virtual Ice	&operator=(const AMateria &other);
	Ice			&operator=(const Ice &other);

	virtual AMateria*	clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif