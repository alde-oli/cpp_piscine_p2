#include "Bureaucrat.hpp"
#include <string>
#include <limits>

void createBureaucrat(Bureaucrat* &bureaucrat)
{
    if (bureaucrat != NULL)
	{
        std::cout << "A bureaucrat already exists." << std::endl;
        return;
    }

    std::string name;
    int grade;
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


void deleteBureaucrat(Bureaucrat* &bureaucrat)
{
    if (bureaucrat == NULL)
        std::cout << "No bureaucrat to delete." << std::endl;
    else
	{
        delete bureaucrat;
        bureaucrat = NULL;
        std::cout << "Bureaucrat deleted." << std::endl;
    }
}

void incrementGrade(Bureaucrat* bureaucrat)
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

void decrementGrade(Bureaucrat* bureaucrat)
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

int main()
{
    Bureaucrat* bureaucrat = NULL;
    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "CREATE")
		{
            createBureaucrat(bureaucrat);
		}
        else if (command == "DELETE")
		{
            deleteBureaucrat(bureaucrat);
		}
        else if (command == "INCR")
		{
            incrementGrade(bureaucrat);
		}
        else if (command == "DECR")
		{
            decrementGrade(bureaucrat);
		}
        else if (command == "EXIT")
		{
            deleteBureaucrat(bureaucrat);
            break;
		}
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}
