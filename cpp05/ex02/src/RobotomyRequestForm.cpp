#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////
//constructors ans destructor//
///////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: AForm(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

////////////////////////
//interaction function//
////////////////////////

void    RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	static bool first = true;
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (bureaucrat.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;
	if (first)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed." << std::endl;
	first = !first;
}