/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:14:17 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 17:32:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low!");
}

Bureaucrat::Bureaucrat(void) : _name("???"), _grade(42)
{	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (150 < grade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	const_cast<std::string &>(_name) = other.getName();
	_grade = other.getGrade();

	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		--_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		++_grade;
}

void	Bureaucrat::signForm(Form &f) const
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed \'" << f.getName() << "\'\n";
	}
	catch (std::exception &e) {
		std::cerr << _name << " couldn't sign \'" << f.getName() << "\' because \"" << e.what() << "\"\n";
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a)
{
	os << a.getName() << ", bureaucrat grade : " << a.getGrade() << "\n";
	return (os);
}
