#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    {
        Bureaucrat tom("Tom", 1);
        std::cout << tom << std::endl;
    }
    try {
        Bureaucrat anna("Anna", 0);
        std::cout << anna << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 151);
        std::cout << bob << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    {
        Bureaucrat alice("Alice", 20);
        try {
            while (true) {
                alice.incrementGrade();
                std::cout << alice << std::endl;
            }
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Bureaucrat alice("Bob", 120);
        try {
            while (true) {
                alice.decrementGrade();
                std::cout << alice << std::endl;
            }
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
