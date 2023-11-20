/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:51:10 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 20:25:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low!");
}

AForm::AForm(void) : _name("???"), _target("???"), _is_signed(false), _sign_grade(42), _exec_grade(42)
{
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : 
_name(name), _target("???"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if (150 < sign_grade || 150 < exec_grade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : 
_name(other.getName()), _target(other.getTarget()), _is_signed(other.getIsSigned()), \
_sign_grade(other.getSignGrade()), _exec_grade(other.getExecGrade())
{
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (other.getName() == "This is bullshit...")
		return (*this);
	else
		return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

std::string	AForm::getTarget(void) const
{
	return (_target);
}

bool		AForm::getIsSigned(void) const
{
	return (_is_signed);
}

int			AForm::getSignGrade(void) const
{
	return (_sign_grade);
}

int			AForm::getExecGrade(void) const
{
	return (_exec_grade);
}

void	AForm::setName(std::string name)
{
	const_cast<std::string &>(_name) = target;
}

void	AForm::setTarget(std::string target)
{
	const_cast<std::string &>(_target) = target;
}

void	AForm::setIsSigned(bool val)
{
	_is_signed = val;
}

void	AForm::setSignGrade(int val)
{
	const_cast<int &>(_sign_grade) = val;
}

void	AForm::setExecGrade(int val)
{
	const_cast<int &>(_exec_grade) = val;
}

void		AForm::beSigned(const Bureaucrat &b)
{
	const int	grade = b.getGrade();

	if (grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade < grade)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &a)
{
	os << "\'" << a.getName() << "\', is signed : " << (a.getIsSigned() == true ? "yes" : "no") << \
		", sign grade : " << a.getSignGrade() << ", exec grade : " << a.getExecGrade() << "\n";
	return (os);
}
