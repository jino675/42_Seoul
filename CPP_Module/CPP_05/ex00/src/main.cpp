/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:48:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 16:43:26 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("bob", 2);
	Bureaucrat	c(b);
	Bureaucrat	d = c;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	try {
		Bureaucrat	f("Michael", 151);
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Bureaucrat	f("Michael", -1);
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Bureaucrat	f("Michael", 1);
		std::cout << f;
		std::cout << "This should be displayed!\n";
		f.incrementGrade();
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Bureaucrat	f("Michael", 150);
		std::cout << f;
		std::cout << "This should be displayed!\n";
		f.decrementGrade();
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}