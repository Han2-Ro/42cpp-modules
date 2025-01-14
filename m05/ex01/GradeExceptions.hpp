#pragma once
#include <exception>

class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw() {
        return "Grade is too high";
    }
};

class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw() {
        return "Grade is too low";
    }
};
