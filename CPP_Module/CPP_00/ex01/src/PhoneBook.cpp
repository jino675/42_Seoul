/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:03 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/23 21:08:42 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : start(0), end(0), cnt(0)
{
}

void	PhoneBook::add(void)
{
	std::string	input[5];

	std::cout << "\nGive me new informations!\n\n";
	std::cout << "First name : ";		std::getline(std::cin, input[0]);
	std::cout << "Last name : ";		std::getline(std::cin, input[1]);
	std::cout << "Nickname : ";			std::getline(std::cin, input[2]);
	std::cout << "Phone number : ";		std::getline(std::cin, input[3]);
	std::cout << "Darkest secret : ";	std::getline(std::cin, input[4]);

	if (cnt == 8) {
		++start;
		if (start > 8)
			start = 0;
	}
	else
		++cnt;
	contacts[end] = Contact(input);
	++end;
	if (end > 8)
		end = 0;
	std::cout << "\nNew Contact is added!\n\n";
}

void	PhoneBook::search(void)
{
	int			cur_idx, input;
	std::string	*ret;

	while (true) {
		cur_idx = start;
		std::cout << "\nThis is your contacts\n\n";
		for (int i = 0; i < cnt; ++i) {
			ret = contacts[cur_idx].get_names();
			std::cout << "|" << std::setw(10) << std::right << i + 1;
			for (int j = 0; j < 3; ++j)
				std::cout << "|" << std::setw(10) << std::right << ret[j];
			std::cout << "|\n";
			delete[] ret;

			++cur_idx;
			if (cur_idx > 8)
				cur_idx -= 9;
		}
		
		if (cnt == 0) {
			std::cout << "\nThere is no contact!\n\n";
			return ;
		}
		std::cout << "\nSelect index : ";	std::cin >> input; std::cin.clear(); std::cin.ignore(LLONG_MAX, '\n');
		if (input >= 1 && input <= cnt) {
			cur_idx = start + input - 1;
			if (cur_idx > 8)
				cur_idx -= 9;
			contacts[cur_idx].display_all();
			return ;
		}
		else
			std::cout << "\nIndex should be between 1 and " << cnt << "\n\n";
	}
}
