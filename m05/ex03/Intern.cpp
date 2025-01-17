#include "Intern.hpp"

#include <iostream>

Intern::Intern() {
    std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern: Copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern: Destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    static const FormType forms[] = {{"shrubbery creation", &createShrubberyForm},
                                     {"robotomy request", &createRobotomyForm},
                                     {"presidential pardon", &createPresidentialForm}};
    static const int      numForms = sizeof(forms) / sizeof(forms[0]);

    for (int i = 0; i < numForms; i++) {
        if (formName == forms[i].name) {
            AForm* form = forms[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}