/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:27:34 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 13:25:42 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
private:
	std::string	_ideas[100];

public:
	Brain(void);
	Brain(const Brain &other);
	~Brain(void);
	Brain	&operator=(const Brain &other);

	void		setIdea(int idx, std::string idea);
	std::string	getIdea(int idx) const;
};

#endif