/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:13:32 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 14:33:26 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria	*_source[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	virtual ~MateriaSource(void);
	MateriaSource &operator=(const MateriaSource &other);

	virtual void 		learnMateria(AMateria *m);
	virtual AMateria*	createMateria(const std::string &type);
};

#endif