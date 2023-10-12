/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:20:21 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:50:43 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void	leak_test(void)
{
	system("leaks animal");
}

int main()
{
	atexit(leak_test);

	Animal		*animal = new Animal;
	Animal		*dog = new Dog;
	Animal		*cat = new Cat;
	WrongAnimal	*w_cat = new WrongCat;
	

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	w_cat->makeSound();

	Animal *temp = new Dog;
	temp->setType("Chihuahua");
	*dog = *temp;
	std::cout << dog->getType() << " " << std::endl;

	delete temp;
	delete w_cat;
	delete cat;
	delete dog;
	delete animal;

	return (0);
}