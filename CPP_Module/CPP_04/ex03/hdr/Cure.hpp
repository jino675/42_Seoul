/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:28:22 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 21:29:35 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &other);
	virtual ~Cure(void);
	virtual Cure	&operator=(const AMateria &other);
	Cure			&operator=(const Cure &other);

	virtual AMateria*	clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif