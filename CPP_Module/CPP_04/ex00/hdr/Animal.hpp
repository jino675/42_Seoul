/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:39:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/07 22:13:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define C_GREEN	"\033[0;32m"
# define C_YELLOW	"\033[0;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[0;35m"
# define C_CYAN		"\033[0;36m"
# define C_NONE		"\033[0m"

# include <iostream>
# include <string>

class Animal {
protected:
	std::string	_type;

public:
	Animal(void);
	Animal(const Animal &other);
	virtual ~Animal(void);
	virtual Animal	&operator=(const Animal &other);

	std::string		getType(void) const;
	void			setType(std::string type);

	virtual void	makeSound(void) const;
};

#endif