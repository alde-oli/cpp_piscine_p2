#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(std::string const &name, int const signGrade, int const execGrade);
		Form(Form const &src);
		virtual ~Form();

		Form				&operator=(Form const &src);

		std::string const	&getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat const &bureaucrat);

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

	private:
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;
};

#endif