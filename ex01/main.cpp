#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test valid form creation
        Form form1("Tax Form", 50, 30);
        std::cout << form1 << std::endl;

        // Test form signing with bureaucrat of sufficient grade
        Bureaucrat john("John", 40);
        john.signForm(form1);
        std::cout << form1 << std::endl;

        // Test form signing with bureaucrat of insufficient grade
        Bureaucrat low("Lowman", 60);
        low.signForm(form1);
        std::cout << form1 << std::endl;

        // Test invalid form creation (grade too high)
        Form form2("Invalid Form", 0, 30);
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Test invalid form creation (grade too low)
        Form form3("Invalid Form", 151, 30);
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl << std::endl;
    }

    return 0;
} 