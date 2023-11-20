/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:51:10 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 17:50:18 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low!");
}

Form::Form(void) : _name("???"), _is_signed(false), _sign_grade(42), _exec_grade(42)
{
}

Form::Form(std::string name, int sign_grade, int exec_grade) : 
_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if (150 < sign_grade || 150 < exec_grade)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : 
_name(other.getName()), _is_signed(other.getIsSigned()), \
_sign_grade(other.getSignGrade()), _exec_grade(other.getExecGrade())
{
}

Form::~Form(void)
{
}

Form	&Form::operator=(const Form &other)
{
	const_cast<std::string &>(_name) = other.getName();
	_is_signed = other.getIsSigned();
	const_cast<int &>(_sign_grade) = other.getSignGrade();
	const_cast<int &>(_exec_grade) = other.getExecGrade();

	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool		Form::getIsSigned(void) const
{
	return (_is_signed);
}

int			Form::getSignGrade(void) const
{
	return (_sign_grade);
}

int			Form::getExecGrade(void) const
{
	return (_exec_grade);
}

void		Form::beSigned(const Bureaucrat &b)
{
	const int	grade = b.getGrade();

	if (grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade < grade)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &a)
{
	os << "\'" << a.getName() << "\', is signed : " << (a.getIsSigned() == true ? "yes" : "no") << \
		", sign grade : " << a.getSignGrade() << ", exec grade : " << a.getExecGrade() << "\n";
	return (os);
}
