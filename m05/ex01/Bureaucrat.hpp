#pragma once
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat {
   private:
    const std::string name_;
    unsigned int      grade_;
    Bureaucrat();

   public:
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
