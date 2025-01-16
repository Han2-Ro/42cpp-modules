#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_bureaucrat_basics() {
    std::cout << "\n=== Testing Bureaucrat Basics ===\n" << std::endl;

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
}

void test_form_creation() {
    std::cout << "\n=== Testing Form Creation ===\n" << std::endl;

    try {
        Form valid("Tax Form", 50, 25);
        std::cout << valid << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    try {
        Form tooHigh("Invalid Form", 0, 25);
        std::cout << tooHigh << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Creation failed as expected: " << e.what() << std::endl;
    }

    try {
        Form tooLow("Invalid Form", 50, 151);
        std::cout << tooLow << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Creation failed as expected: " << e.what() << std::endl;
    }
}

void test_form_signing() {
    std::cout << "\n=== Testing Form Signing ===\n" << std::endl;

    Form taxForm("Tax Form", 50, 25);
    Form topSecretForm("Top Secret", 1, 1);

    Bureaucrat lowLevel("Intern", 100);
    Bureaucrat midLevel("Officer", 50);
    Bureaucrat highLevel("Director", 1);

    std::cout << "\nTesting low level bureaucrat:" << std::endl;
    std::cout << lowLevel << " attempts to sign forms:" << std::endl;
    lowLevel.signForm(taxForm);
    lowLevel.signForm(topSecretForm);

    std::cout << "\nTesting mid level bureaucrat:" << std::endl;
    std::cout << midLevel << " attempts to sign forms:" << std::endl;
    midLevel.signForm(taxForm);
    midLevel.signForm(topSecretForm);

    std::cout << "\nTesting high level bureaucrat:" << std::endl;
    std::cout << highLevel << " attempts to sign forms:" << std::endl;
    highLevel.signForm(taxForm);
    highLevel.signForm(topSecretForm);
}

int main() {
    test_bureaucrat_basics();
    test_form_creation();
    test_form_signing();
    return 0;
}
