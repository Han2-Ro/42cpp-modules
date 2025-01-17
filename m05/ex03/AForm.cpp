#include "AForm.hpp"

AForm::AForm() : name_("default"), is_signed_(false), grade_to_sign_(150), grade_to_execute_(150) {
    std::cout << "AForm: Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute)
    : name_(name),
      is_signed_(false),
      grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute) {
    std::cout << "AForm: Parameter constructor called" << std::endl;
    if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
    : name_(other.name_),
      is_signed_(other.is_signed_),
      grade_to_sign_(other.grade_to_sign_),
      grade_to_execute_(other.grade_to_execute_) {
    std::cout << "AForm: Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm: Copy assignment operator called" << std::endl;
    if (this != &other) {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm: Destructor called" << std::endl;
}

std::string AForm::getName() const {
    return name_;
}

bool AForm::getIsSigned() const {
    return is_signed_;
}

unsigned int AForm::getGradeToSign() const {
    return grade_to_sign_;
}

unsigned int AForm::getGradeToExecute() const {
    return grade_to_execute_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= grade_to_sign_) {
        is_signed_ = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::checkExecutionRequirements(Bureaucrat const& executor) const {
    if (!is_signed_) {
        throw std::runtime_error("Form is not signed");
    }
    if (executor.getGrade() > grade_to_execute_) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form: grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form: grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << " (sign grade: " << form.getGradeToSign()
       << ", execute grade: " << form.getGradeToExecute()
       << ", signed: " << (form.getIsSigned() ? "yes" : "no") << ")";
    return os;
}
