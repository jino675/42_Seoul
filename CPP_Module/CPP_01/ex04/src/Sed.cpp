/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:44:11 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 16:03:29 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	Sed(std::string filename, std::string s1, std::string s2)
{
	size_t		cur_idx;
	std::string	cur_line, new_line;

	std::ifstream infile(filename, std::ios::in);
	std::ofstream outfile(filename + ".replace", std::ios::out | std::ios::trunc);
	if (infile.fail() == true || outfile.fail() == true) {
		std::cout << "open error!\n";
		exit (1);
	}
	while (std::getline(infile, cur_line) != 0) {
		cur_idx = cur_line.find(s1, 0);
		if (cur_idx != std::string::npos) {
			new_line = cur_line.substr(0, cur_idx);
			new_line += s2;
			new_line += cur_line.substr(cur_idx + s1.size());
			outfile << new_line;
		}
		else
			outfile << cur_line;
		if (infile.eof() == false)
			outfile << "\n";
	}
	infile.close();
	outfile.close();
}