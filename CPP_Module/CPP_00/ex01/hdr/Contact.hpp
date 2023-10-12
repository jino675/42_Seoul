/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:02:37 by jiryu             #+#    #+#             */
/*   Updated: 2023/09/30 15:01:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
private:
	std::string	strs[5];

public:
	Contact();
	
	void		set_infos(std::string info[5]);
	void		display_all(void);
	std::string	get_info(int idx);
};

#endif