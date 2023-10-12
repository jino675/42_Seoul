/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:15:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:44:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		_source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
		_source[i] = NULL;
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		if (_source[i] != NULL)
			delete _source[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i) {
		if (_source[i] != NULL) {
			delete _source[i];
			_source[i] = NULL;
		}
		if (other._source[i] != NULL)
			_source[i] = other._source[i]->clone();
	}

	return (*this);
}

void 		MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i) {
		if (_source[i] == NULL) {
			_source[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
		if (_source[i] != NULL && _source[i]->getType() == type)
			return (_source[i]->clone());
	return (NULL);
}