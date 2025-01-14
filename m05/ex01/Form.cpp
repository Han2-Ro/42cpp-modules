#include "Form.hpp"

Form::Form() : name_("default"), is_signed_(false), grade_to_sign_(150), grade_to_execute_(150) {
    std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute)
    : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute) {
    std::cout << "Form: Parameter constructor called" << std::endl;
    if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : name_(other.name_), is_signed_(other.is_signed_),
      grade_to_sign_(other.grade_to_sign_), grade_to_execute_(other.grade_to_execute_) {
    std::cout << "Form: Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form: Copy assignment operator called" << std::endl;
    if (this != &other) {
        is_signed_ = other.is_signed_;
        // Note: can't assign const members
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form: Destructor called" << std::endl;
}

std::string Form::getName() const {
    return name_;
}

bool Form::getIsSigned() const {
    return is_signed_;
}

unsigned int Form::getGradeToSign() const {
    return grade_to_sign_;
}

unsigned int Form::getGradeToExecute() const {
    return grade_to_execute_;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= grade_to_sign_) {
        is_signed_ = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << " (sign grade: " << form.getGradeToSign()
       << ", execute grade: " << form.getGradeToExecute()
       << ", signed: " << (form.getIsSigned() ? "yes" : "no") << ")";
    return os;
}
