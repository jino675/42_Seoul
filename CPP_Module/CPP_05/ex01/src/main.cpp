/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:48:19 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 17:32:44 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Form	a;
	Form	b("Launch a Missile", 10, 20);
	Form	c(b);
	Form	d = c;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	try {
		Form	f("Shoot a gun", 50, 151);
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		Form	f("Shoot a gun", 151, 15);
		std::cout << f;
		std::cout << "This should not be displayed!\n";
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Bureaucrat	f("Michael", 10);
		std::cout << f;
		f.signForm(b);
		f.decrementGrade();
		std::cout << f;
		f.signForm(b);
	}
	catch(std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}