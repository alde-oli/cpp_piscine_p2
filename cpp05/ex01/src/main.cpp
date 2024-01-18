#include "Bureaucrat.hpp"
#include <string>
#include <limits>

int	chooseBureaucrat(Bureaucrat* bureaucrat[5])
{
	int i = 0;
	int j = 0;

	std::cout << "Choose a bureaucrat:" << std::endl;
	while (i < 5 && bureaucrat[i] != NULL)
	{
		std::cout << i << ": " << bureaucrat[i]->getName() << ", " << bureaucrat[i]->getGrade() << std::endl;
		i++;
	}
	while (!(std::cin >> j) || j < 0 || j >= i)
	{
		std::cout << "Invalid bureaucrat. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (j);
}

int	chooseForm(Form* form[5])
{
	int i = 0;
	int j = 0;

	std::cout << "Choose a form:" << std::endl;
	while (i < 5 && form[i] != NULL)
	{
		std::cout << i << ": " << form[i]->getName() << ", " << form[i]->getSignGrade() << ", " << form[i]->getExecGrade() << ", " << form[i]->getIsSigned() << std::endl;
		i++;
	}
	while (!(std::cin >> j) || j < 0 || j >= i)
	{
		std::cout << "Invalid form. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (j);
}

void	createForm(Form* &form)
{
	std::string	name;
	int			signGrade;
	int			execGrade;

	std::cout << "Enter form's name: ";
	while (std::getline(std::cin, name) && name.empty())
	{
		std::cout << "Please enter a name: ";
	}
	std::cout << "Enter form's sign grade: ";
	while (!(std::cin >> signGrade))
	{
		std::cout << "Invalid sign grade. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Enter form's exec grade: ";
	while (!(std::cin >> execGrade))
	{
		std::cout << "Invalid exec grade. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	try
	{
		form = new Form(name, signGrade, execGrade);
		std::cout << "Form " << form->getName() << " with sign grade " << form->getSignGrade() << " and exec grade " << form->getExecGrade() << " created." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	createBureaucrat(Bureaucrat* &bureaucrat)
{
	std::string	name;
	int			grade;

	std::cout << "Enter bureaucrat's name: ";
	while (std::getline(std::cin, name) && name.empty())
	{
		std::cout << "Please enter a name: ";
	}
	std::cout << "Enter bureaucrat's grade: ";
	while (!(std::cin >> grade))
	{
		std::cout << "Invalid grade. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	try
	{
		bureaucrat = new Bureaucrat(name, grade);
		std::cout << "Bureaucrat " << bureaucrat->getName() << " with grade " << bureaucrat->getGrade() << " created." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	incrementGrade(Bureaucrat* bureaucrat)
{
	if (bureaucrat == NULL)
	{
		std::cout << "No bureaucrat to increment grade." << std::endl;
		return;
	}

	try
	{
		bureaucrat->incrementGrade();
		std::cout << "Bureaucrat " << bureaucrat->getName() << " incremented to grade " << bureaucrat->getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	decrementGrade(Bureaucrat* bureaucrat)
{
	if (bureaucrat == NULL)
	{
		std::cout << "No bureaucrat to decrement grade." << std::endl;
		return;
	}

	try
	{
		bureaucrat->decrementGrade();
		std::cout << "Bureaucrat " << bureaucrat->getName() << " decremented to grade " << bureaucrat->getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	showAll(Bureaucrat* bureaucrat[5], Form* form[5])
{
	int i = 0;

	std::cout << std::endl << "Bureaucrats:" << std::endl;
	while (i < 5 && bureaucrat[i] != NULL)
	{
		std::cout << bureaucrat[i]->getName() << ", " << bureaucrat[i]->getGrade() << std::endl;
		i++;
	}
	i = 0;
	std::cout << std::endl << "Forms:" << std::endl;
	while (i < 5 && form[i] != NULL)
	{
		std::cout << form[i]->getName() << ", " << form[i]->getSignGrade() << ", " << form[i]->getExecGrade() << ", " << form[i]->getIsSigned() << std::endl;
		i++;
	}
}

void	deleteAll(Bureaucrat* bureaucrat[5], Form* form[5])
{
	int i = 0;

	while (i < 5 && bureaucrat[i] != NULL)
	{
		delete bureaucrat[i];
		bureaucrat[i] = NULL;
		std::cout << "Bureaucrat " << i << " deleted." << std::endl;
		i++;
	}
	i = 0;
	while (i < 5 && form[i] != NULL)
	{
		delete form[i];
		form[i] = NULL;
		std::cout << "Form " << i << " deleted." << std::endl;
		i++;
	}
}

int main()
{
	Bureaucrat*     bureaucrat[5] = {NULL, NULL, NULL, NULL, NULL};
	Form*           form[5] = {NULL, NULL, NULL, NULL, NULL};
	std::string		command;
	int				i = 0;
	int				j = 0;

	while (true) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (command == "NEWB")
		{
			i = 0;
			while (i < 5 && bureaucrat[i] != NULL)
				i++;
			if (i == 5)
				std::cout << "No more space for bureaucrats." << std::endl;
			else
				createBureaucrat(bureaucrat[i]);
		}
		else if (command == "DELB")
		{
			if (bureaucrat[0] == NULL)
				std::cout << "No bureaucrat to delete." << std::endl;
			else
			{
				i = chooseBureaucrat(bureaucrat);
				delete(bureaucrat[i]);
				bureaucrat[i] = NULL;
			}
		}
		else if (command == "NEWF")
		{
			i = 0;
			while (i < 5 && form[i] != NULL)
				i++;
			if (i == 5)
				std::cout << "No more space for forms." << std::endl;
			else
				createForm(form[i]);
		}
		else if (command == "DELF")
		{
			if (form[0] == NULL)
				std::cout << "No form to delete." << std::endl;
			else
			{
				i = chooseForm(form);
				delete(form[i]);
				form[i] = NULL;
			}
		}
		else if (command == "SIGN")
		{
			if (bureaucrat[0] == NULL)
				std::cout << "No bureaucrat to sign." << std::endl;
			else if (form[0] == NULL)
				std::cout << "No form to sign." << std::endl;
			else
			{
				i = chooseBureaucrat(bureaucrat);
				j = chooseForm(form);
				bureaucrat[i]->signForm(*form[j]);
			}
		}
		else if (command == "INCR")
		{
			if (bureaucrat[0] == NULL)
				std::cout << "No bureaucrat to increment grade." << std::endl;
			else
			{
				i = chooseBureaucrat(bureaucrat);
				incrementGrade(bureaucrat[i]);
			}
		}
		else if (command == "DECR")
		{
			if (bureaucrat[0] == NULL)
				std::cout << "No bureaucrat to decrement grade." << std::endl;
			else
			{
				i = chooseBureaucrat(bureaucrat);
				decrementGrade(bureaucrat[i]);
			}
		}
		else if (command == "LIST")
		{
			showAll(bureaucrat, form);
		}
		else if (command == "EXIT")
		{
			deleteAll(bureaucrat, form);
			break;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
