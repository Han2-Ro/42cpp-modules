#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target_("default") {
    std::srand(std::time(NULL));
    std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {
    std::srand(std::time(NULL));
    std::cout << "RobotomyRequestForm: Parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target_(other.target_) {
    std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    checkExecutionRequirements(executor);
    std::cout << "* DRILLING NOISES * Bzzzz... Whirrr... Clank!" << std::endl;
    if (std::rand() % 2) {
        std::cout << target_ << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target_ << "." << std::endl;
    }
}
