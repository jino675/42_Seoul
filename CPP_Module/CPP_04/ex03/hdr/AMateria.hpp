/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:44:24 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/07 23:11:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define C_GREEN	"\033[0;32m"
# define C_YELLOW	"\033[0;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[0;35m"
# define C_CYAN		"\033[0;36m"
# define C_NONE		"\033[0m"

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {
protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	virtual ~AMateria(void);
	virtual AMateria	&operator=(const AMateria &other);

	const std::string	&getType(void) const;
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter &target);
};

#endif