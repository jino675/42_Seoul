/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:39:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 12:16:37 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define C_GREEN	"\033[0;32m"
# define C_YELLOW	"\033[0;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[0;35m"
# define C_CYAN		"\033[0;36m"
# define C_NONE		"\033[0m"

# include <iostream>
# include <string>

class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal(void);
	WrongAnimal	&operator=(const WrongAnimal &other);

	std::string		getType(void) const;
	void			setType(std::string type);

	void	makeSound(void) const;
};

#endif