/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:03 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:01:50 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int my_getline(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof() == false) {
		if (str.empty() == true)
			return (-1);
		else {
			std::string::iterator iter = str.begin();
			while (iter != str.end() && std::isspace(*iter) == true)
				++iter;
			if (iter == str.end())
				return (-1);
			else
				return (0);
		}
	}
	return (0);
}

PhoneBook::PhoneBook() : start(0), end(0), cnt(0)
{
}

void	PhoneBook::add(void)
{
	std::string	input[5];

	std::cout << "\nGive me new informations!\n\n";
	
	do {std::cout << "First name : ";}
	while (my_getline(input[0]) == -1);
	do {std::cout << "Last name : ";}
	while (my_getline(input[1]) == -1);
	do {std::cout << "Nickname : ";}
	while (my_getline(input[2]) == -1);
	do {std::cout << "Phone number : ";}
	while (my_getline(input[3]) == -1);
	do {std::cout << "Darkest secret : ";}
	while (my_getline(input[4]) == -1);

	if (cnt == 8) {
		++start;
		if (start > 8)
			start = 0;
	}
	else
		++cnt;
	contacts[end].set_infos(input);
	++end;
	if (end > 8)
		end = 0;
	if (std::cin.eof() == false)
		std::cout << "\nNew Contact is added!\n\n";
	else
		std::exit(EXIT_SUCCESS);
}

void	PhoneBook::search(void)
{
	int			cur_idx, input;
	std::string	ret;

		
	if (cnt == 0) {
		std::cout << "\nThere is no contact!\n\n";
		return ;
	}
	while (std::cin.eof() == false) {
		cur_idx = start;
		std::cout << "\nThese are your contacts\n\n";
		for (int i = 0; i < cnt; ++i) {
			std::cout << "|" << std::setw(10) << std::right << i + 1;
			for (int j = 0; j < 3; ++j) {
				ret = contacts[cur_idx].get_info(j);
				if (ret.size() > 10) {
					ret = ret.substr(0, 9);
					ret += ".";
				}
				std::cout << "|" << std::setw(10) << std::right << ret;
			}
			std::cout << "|\n";

			++cur_idx;
			if (cur_idx > 8)
				cur_idx -= 9;
		}
		
		std::cout << "\nSelect index : ";	std::cin >> input; std::cin.clear(); std::cin.ignore(LLONG_MAX, '\n');
		if (input >= 1 && input <= cnt) {
			cur_idx = start + input - 1;
			if (cur_idx > 8)
				cur_idx -= 9;
			contacts[cur_idx].display_all();
			return ;
		}
		else if (std::cin.eof() == false)
			std::cout << "\nIndex should be between 1 and " << cnt << "\n\n";
		else
			std::exit(EXIT_SUCCESS);
	}
}
