/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:11:31 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 14:33:34 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource(void) {}

	virtual void 		learnMateria(AMateria *m) = 0;
	virtual AMateria*	createMateria(const std::string &type) = 0;
};

#endif