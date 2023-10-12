/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:09:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/07 22:13:16 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &other);
	virtual ~Cat(void);
	virtual Cat	&operator=(const Animal &other);
	Cat	&operator=(const Cat &other);

	virtual void	makeSound(void) const;
};

#endif