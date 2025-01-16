#pragma once
#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
   private:
    const std::string name_;
    unsigned int      grade_;

   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string  getName() const;
    unsigned int getGrade() const;
    void         incrementGrade();
    void         decrementGrade();
    void         signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
