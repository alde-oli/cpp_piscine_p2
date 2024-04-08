#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////
//constructors and destructor//
///////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/////////////////////////
//interactions function//
/////////////////////////

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (bureaucrat.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}