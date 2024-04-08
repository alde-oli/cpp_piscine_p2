#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string const &name, std::string const &target, int const signGrade, int const execGrade);
		AForm(AForm const &src);
		virtual ~AForm();

		AForm				&operator=(AForm const &src);

		std::string const	&getName() const;
		std::string const	&getTarget() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &bureaucrat) const = 0;

		class				GradeTooHighException
			: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class				GradeTooLowException
			: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class				FormAlreadySignedException
			: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class			FormNotSignedException
			: public std::exception
		{
			virtual const char	*what() const throw();
		};

	protected:
		std::string const	_name;
		std::string const	_target;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;
};

#endif