/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:40:02 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/04 19:52:14 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define COLOR_GREEN	"\033[0;32m"
# define COLOR_YELLOW	"\033[0;33m"
# define COLOR_BLUE		"\033[0;34m"
# define COLOR_PURPLE	"\033[0;35m"
# define COLOR_CYAN		"\033[0;36m"
# define COLOR_NONE		"\033[0m"

# define CLAP_HP		10
# define CLAP_EP		10
# define CLAP_DP		0
# define CLAP_HP_MAX	10

# include <iostream>
# include <string>

class ClapTrap {
private:
	std::string	_name;
	int			_HP;
	int			_EP;
	int			_DP;
	int			_HP_MAX;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	virtual ~ClapTrap(void);
	ClapTrap	&operator=(const ClapTrap &other);

	virtual void	attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void		printInfo(void);

	void		setName(const std::string name);
	void		setHP(const int HP);
	void		setEP(const int EP);
	void		setDP(const int DP);
	void		setHP_MAX(const int HP_MAX);

	std::string getName(void) const;
	int 		getHP(void) const;
	int			getEP(void) const;
	int			getDP(void) const;
	int 		getHP_MAX(void) const;
			
};

#endif