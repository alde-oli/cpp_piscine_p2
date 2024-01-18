#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <string>
#include <limits>


void	showAll(Intern* slaves[5], AForm* form[5])
{
	int i = 0;

	std::cout << std::endl << "Slaves:" << std::endl;
	while (i < 5 && slaves[i] != NULL)
	{
		std::cout << "slave ID(pointer adress): "<< slaves[i] << std::endl;
		i++;
	}
	i = 0;
	std::cout << std::endl << "Forms:" << std::endl;
	while (i < 5 && form[i] != NULL)
	{
		std::cout << form[i]->getName() << ", " << form[i]->getTarget() << ", " << form[i]->getSignGrade() << ", " << form[i]->getExecGrade() << ", " << form[i]->getIsSigned() << std::endl;
		i++;
	}
}

int		chooseSlave(Intern* slaves[5])
{
	int i = 0;
	int choice = 0;

	std::cout << "Choose a slave: " << std::endl;
	while (i < 5 && slaves[i] != NULL)
	{
		std::cout << i << ": " << slaves[i] << std::endl;
		i++;
	}
	std::cout << "Choice: ";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice < 0 || choice > 4 || slaves[choice] == NULL)
	{
		std::cout << "Invalid choice." << std::endl;
		return chooseSlave(slaves);
	}
	return choice;
}

void	deleteAll(Intern* slaves[5], AForm* form[5])
{
	int i = 0;

	while (i < 5 && slaves[i] != NULL)
	{
		delete slaves[i];
		slaves[i] = NULL;
		std::cout << "Slave " << i << " deleted." << std::endl;
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
	Intern*     slaves[5] = {NULL, NULL, NULL, NULL, NULL};
	AForm*           form[5] = {NULL, NULL, NULL, NULL, NULL};
	std::string		command;
	std::string		formName;
	std::string		target;
	int				i = 0;
	int				j = 0;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (command == "NEWI")
		{
			i = 0;
			while (i < 5 && slaves[i] != NULL)
				i++;
			if (i == 5)
				std::cout << "No space available for more slaves." << std::endl;
			else
			{
				slaves[i] = new Intern();
				std::cout << "Slave " << i << " created." << std::endl;
			}
		}
		else if (command == "NEWF")
		{
			if (slaves[0] == NULL)
			{
				std::cout << "No slaves available." << std::endl;
				continue ;
			}
			i = chooseSlave(slaves);
			j = 0;
			while (j < 5 && form[j] != NULL)
				j++;
			if (j == 5)
				std::cout << "No space available for more forms." << std::endl;
			else
			{
				std::cout << "Enter form name: ";
				while (std::getline(std::cin, formName) && formName.empty())
					std::cout << "Invalid form name. Try again: ";
				std::cout << "Enter target: ";
				while (std::getline(std::cin, target) && target.empty())
					std::cout << "Invalid target. Try again: ";
				try
				{
					form[j] = slaves[i]->makeForm(formName, target);
					std::cout << "Form created." << std::endl;
				}
				catch (std::exception &e)
				{
					std::cout << "Exception: " << e.what() << std::endl;
				}
			}
		}
		else if (command == "DEL")
		{
			i = chooseSlave(slaves);
			delete slaves[i];
			slaves[i] = NULL;
			std::cout << "Slave " << i << " deleted." << std::endl;
			while (i < 4 && slaves[i + 1] != NULL)
			{
				slaves[i] = slaves[i + 1];
				slaves[i + 1] = NULL;
				i++;
			}
		}
		else if (command == "LIST")
		{
			showAll(slaves, form);
		}
		else if (command == "EXIT")
		{
			deleteAll(slaves, form);
			break ;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
