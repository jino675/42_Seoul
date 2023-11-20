/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:46:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 17:26:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

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
	Form(void);
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form &other);
	~Form(void);
	Form	&operator=(const Form &other);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	void		beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &a);

#endif