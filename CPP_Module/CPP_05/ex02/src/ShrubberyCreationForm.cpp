/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:18:20 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/22 20:44:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const AForm &other)
{
	*this = dynamic_cast<ShrubberyCreationForm &>(other);
	
	return (*this);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	setName(other.getName());
	setTarget(other.getTarget());
	setIsSigned(other.getIsSigned());
	setSignGrade(other.getSignGrade());
	setExecGrade(other.getExecGrade());

	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	outfile(getTarget() + "_shrubbery", std::ios::out | std::ios::trunc);
	
	if (outfile.fail() == true) {
		std::cerr << "open error!\n";
		exit (1);
	}
	outfile << "
                                                    .
                                     .         ;
        .              .              ;%     ;;
          ,           ,                :;%  %;
           :         ;                   :;%;'     .,
  ,.        %;     %;            ;        %;'    ,;
    ;       ;%;  %%;        ,     %;    ;%;    ,%'
     %;       %;%;      ,  ;       %;  ;%;   ,%;'
      ;%;      %;        ;%;        % ;%;  ,%;'
       `%;.     ;%;     %;'         `;%%;.%;'
        `:;%.    ;%%. %@;        %; ;@%;%'
           `:%;.  :;bd%;          %;@%;'
             `@%:.  :;%.         ;@@%;'
               `@%.  `;@%.      ;@@%;
                 `@%%. `@%%    ;@@%;
                   ;@%. :@%%  %@@%;
                     %@bd%%%bd%%:;
                       #@%%%%%:;;
                       %@@%%%::;
                       %@@@%(o);  . '
                       %@@@o%;:(.,'
                   `.. %@@@o%::;
                      `)@@@o%::;
                       %@@(o)::;
                      .%@@@@%::;
                      ;%@@@@%::;.
                     ;%@@@@%%:;;;.
                 ...;%@@@@@%%:;;;;,..";
	outfile.close();
}
