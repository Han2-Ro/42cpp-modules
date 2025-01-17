#pragma once

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    struct FormType {
        std::string name;
        AForm* (*creator)(const std::string&);
    };

    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPresidentialForm(const std::string& target);
}; 