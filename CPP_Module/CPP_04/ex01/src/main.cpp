/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:20:21 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/08 16:48:57 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

static void	leak_test(void)
{
	system("leaks animal");
}

int main()
{
	atexit(leak_test);

	Animal		*animals[4];
	
	for (int i = 0; i < 4; ++i) {
		if (i < 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}

	for (int i = 0; i < 4; ++i)
		animals[i]->makeSound();
	
	animals[0]->setBrain("hello");
	animals[0]->printBrain();
	animals[1]->setBrain("Bye");
	animals[1]->printBrain();
	*animals[0] = *animals[1];
	animals[0]->printBrain();

	Dog a;
	a.setBrain("hahaha");
	Dog b(a);
	
	b.printBrain();

	for (int i = 0; i < 4; ++i)
		delete animals[i];

	return (0);
}