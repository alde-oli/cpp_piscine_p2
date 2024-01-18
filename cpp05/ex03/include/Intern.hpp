#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class	Intern
{
    public:
        Intern();
        Intern(Intern const &src);
        ~Intern();

        Intern	&operator=(Intern const &src);

        AForm	*makeForm(std::string const &name, std::string const &target) const;

        class	InvalidFormNameException
            : public std::exception
        {
            virtual const char *what() const throw();
        };
};

#endif