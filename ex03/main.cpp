#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat high("High", 1);
        Bureaucrat medium("Medium", 50);
        Bureaucrat low("Low", 150);

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        // Try to execute unsigned form
        high.executeForm(shrubbery);

        // Sign and execute form
        high.signForm(shrubbery);
        high.executeForm(shrubbery);

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;

        // Try to execute with low grade
        low.signForm(robotomy);
        low.executeForm(robotomy);

        // Sign and execute with sufficient grade
        medium.signForm(robotomy);
        medium.executeForm(robotomy);

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Zaphod");
        std::cout << pardon << std::endl;

        // Try to execute with medium grade
        medium.signForm(pardon);
        medium.executeForm(pardon);

        // Sign and execute with high grade
        high.signForm(pardon);
        high.executeForm(pardon);

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl << std::endl;
    }

    return 0;
} 