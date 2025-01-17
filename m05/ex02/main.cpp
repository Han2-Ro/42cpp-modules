#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_shrubbery_form() {
    std::cout << "\n=== Testing ShrubberyCreationForm ===\n" << std::endl;

    ShrubberyCreationForm form("garden");
    Bureaucrat            low("Intern", 150);
    Bureaucrat            mid("Officer", 137);
    Bureaucrat            high("Director", 1);

    std::cout << form << std::endl;

    // Test with too low grade
    low.signForm(form);
    low.executeForm(form);

    // Test with enough grade to execute but not signed
    mid.executeForm(form);

    // Test with enough grade to sign and execute
    high.signForm(form);
    mid.executeForm(form);
}

void test_robotomy_form() {
    std::cout << "\n=== Testing RobotomyRequestForm ===\n" << std::endl;

    RobotomyRequestForm form("Bender");
    Bureaucrat          low("Intern", 150);
    Bureaucrat          mid("Officer", 72);
    Bureaucrat          high("Director", 1);

    std::cout << form << std::endl;

    // Test signing with enough grade
    mid.signForm(form);

    // Test executing with too low grade
    mid.executeForm(form);

    // Test proper execution
    high.executeForm(form);
    high.executeForm(form);
}

void test_presidential_form() {
    std::cout << "\n=== Testing PresidentialPardonForm ===\n" << std::endl;

    PresidentialPardonForm form("Arthur Dent");
    Bureaucrat             mid("Officer", 25);
    Bureaucrat             high("Director", 1);

    std::cout << form << std::endl;

    // Test signing with grade too low to execute
    mid.signForm(form);
    mid.executeForm(form);

    // Test proper execution
    high.executeForm(form);
}

int main() {
    test_shrubbery_form();
    test_robotomy_form();
    test_presidential_form();
    return 0;
}
