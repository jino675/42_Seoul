/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:00:53 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/29 19:32:39 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[9];
	int		start;
	int		end;
	int		cnt;

public:
	PhoneBook();

	void	add(void);
	void	search(void);
};
 
#endif