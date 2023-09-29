/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:02:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/23 19:57:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
public:
	std::string	strs[5];

	Contact();
	Contact(std::string	input[5]);
	
	void		display_all(void);
	std::string	*get_names(void);

	Contact	&operator=(Contact const &a)
	{
		for (int i = 0; i < 5; ++i)
			strs[i] = a.strs[i];
		return *this;
	}
};

#endif