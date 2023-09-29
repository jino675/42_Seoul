/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:42:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/24 19:53:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str("Hi THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string : " << &str << "\n";
	std::cout << "The memory address held by stringPTR : " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF : " << &stringREF << "\n";

	std::cout << "The value of the string variable : " << str << "\n";
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF : " << stringREF << "\n";

	return (1);
}