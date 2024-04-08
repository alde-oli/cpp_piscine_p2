#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat			&operator=(Bureaucrat const &src);

		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		std::string const	&getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		
		class				GradeTooHighException
			: public std::exception
		{
			virtual const char *what() const throw();
		};
		class				GradeTooLowException
			: public std::exception
		{
			virtual const char *what() const throw();
		};

		private:
		std::string const	_name;
		int					_grade;
};

#endif
