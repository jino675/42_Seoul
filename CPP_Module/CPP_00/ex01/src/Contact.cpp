/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:25:35 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/23 19:58:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string input[5])
{
	for (int i = 0; i < 5; ++i)
		strs[i] = input[i];
}

void	Contact::display_all(void)
{
	std::cout << "\n";
	std::cout << "First name : " << this->strs[0] << "\n";
	std::cout << "Last name : " << this->strs[1] << "\n";
	std::cout << "Nickname : " << this->strs[2] << "\n";
	std::cout << "Phone number : " << this->strs[3] << "\n";
	std::cout << "Darkest secret : " << this->strs[4] << "\n";
	std::cout << "\n";
}

std::string	*Contact::get_names(void)
{
	std::string	*res;

	res = new std::string[3];
	for (int i = 0; i < 3; ++i) {
		if (strs[i].size() > 10) {
			res[i] = strs[i].substr(0, 9);
			res[i] += ".";
		}
		else
			res[i] = strs[i];
	}
	return (res);
}