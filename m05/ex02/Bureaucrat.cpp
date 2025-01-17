#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name_(name), grade_(grade) {
    std::cout << "Bureaucrat: Parameter constructor called" << std::endl;
    if (grade_ < 1) {
        throw GradeTooHighException();
    } else if (grade_ > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    this->grade_ = other.grade_;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat (" << name_ << "): Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return name_;
}

unsigned int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ <= 1) {
        throw GradeTooHighException();
    } else {
        grade_--;
    }
}

void Bureaucrat::decrementGrade() {
    if (grade_ >= 150) {
        throw GradeTooLowException();
    } else {
        grade_++;
    }
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << name_ << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name_ << " couldn't execute " << form.getName() << " because " << e.what()
                  << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
