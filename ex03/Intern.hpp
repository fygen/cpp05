#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target);
    struct FormType {
        std::string name;
        FormCreator creator;
    };
    static const FormType formTypes[3];

    AForm* createShrubberyForm(const std::string& target);
    AForm* createRobotomyForm(const std::string& target);
    AForm* createPresidentialForm(const std::string& target);

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif 