#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

///////////////////////////////
//Constructors and destructor//
///////////////////////////////

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern()
{
}

//////////////////////
//Operators overload//
//////////////////////

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

//////////////
//exceptions//
//////////////

const char *Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid form name");
}

/////////////////////////
//interaction functions//
/////////////////////////

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	AForm	*form;

	if (name == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	else if (name == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	else if (name == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	else
		throw InvalidFormNameException();
	return (form);
}