/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:02:25 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/05 15:15:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
private:
	Brain	*_brain;

public:
	Dog(void);
	Dog(const Dog &other);
	virtual ~Dog(void);
	virtual Dog	&operator=(const Animal &other);
	Dog	&operator=(const Dog &other);

	virtual void	makeSound(void) const;
	virtual void	setBrain(std::string idea);
	virtual Brain	*getBrain(void) const;
	virtual void	printBrain(void) const;
};

#endif