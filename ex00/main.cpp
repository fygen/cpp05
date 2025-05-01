#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Test valid bureaucrat creation
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Test grade increment
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        // Test grade decrement
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        // Test grade too high
        Bureaucrat high("Highman", 1);
        std::cout << high << std::endl;
        high.incrementGrade(); // Should throw exception

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Test grade too low
        Bureaucrat low("Lowman", 150);
        std::cout << low << std::endl;
        low.decrementGrade(); // Should throw exception

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Test invalid grade in constructor
        Bureaucrat invalid("Invalid", 0); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Test invalid grade in constructor
        Bureaucrat invalid("Invalid", 151); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl << std::endl;
    }

    return 0;
} 