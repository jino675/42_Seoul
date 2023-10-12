/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:29:08 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 15:01:03 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "(It seems to be thinking of something...)\n";
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "(It seems to be thinking of something...)\n";
}
	
Brain::~Brain(void)
{
	std::cout << "(It looks just peaceful...)\n";
}

Brain	&Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		setIdea(i, other.getIdea(i));
	return (*this);
}

void	Brain::setIdea(int idx, std::string idea)
{
	_ideas[idx] = idea;
}

std::string	Brain::getIdea(int idx) const
{
	return (_ideas[idx]);
}