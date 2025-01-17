#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target_("default") {
    std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {
    std::cout << "PresidentialPardonForm: Parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target_(other.target_) {
    std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecutionRequirements(executor);
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
