#include "Form.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////
//constructors and destructor//
///////////////////////////////

Form::Form(std::string const &name, int const signGrade, int const execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(Form const &src)
	: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form::~Form()
{
}

/////////////////////
//operator overload//
/////////////////////

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

//////////////
//exceptions//
//////////////

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed.");
}

///////////////////////
//getters and setters//
///////////////////////

std::string const	&Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (this->_isSigned)
		throw Form::FormAlreadySignedException();
	this->_isSigned = true;
}
