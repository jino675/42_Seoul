/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:46:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 20:20:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	const std::string	_target;
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
	AForm(void);
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm(const Form &other);
	virtual ~AForm(void);
	virtual AForm	&operator=(const AForm &other);

	std::string		getName(void) const;
	std::string		getTarget(void) const;
	bool			getIsSigned(void) const;
	int				getSignGrade(void) const;
	int				getExecGrade(void) const;

	void	setName(std::string name);
	void	setTarget(std::string target);
	void	setIsSigned(bool val);
	void	setSignGrade(int val);
	void	setExecGrade(int val);

	void			beSigned(const Bureaucrat &signer);
	virtual void	execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &a);

#endif