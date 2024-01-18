#include "AForm.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////
//constructors and destructor//
///////////////////////////////

AForm::AForm(std::string const &name, std::string const &target, int const signGrade, int const execGrade)
	: _name(name), _target(target), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(AForm const &src)
	: _name(src._name), _target(src._target), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

AForm::~AForm()
{
}

/////////////////////
//operator overload//
/////////////////////

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

//////////////
//exceptions//
//////////////

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed.");
}

///////////////////////
//getters and setters//
///////////////////////

std::string const	&AForm::getName() const
{
	return (this->_name);
}

std::string const	&AForm::getTarget() const
{
	return (this->_target);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else if (this->_isSigned)
		throw AForm::FormAlreadySignedException();
	this->_isSigned = true;
}
