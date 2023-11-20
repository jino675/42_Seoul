/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:50:30 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 17:23:21 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &other);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form &f) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a);

#endif