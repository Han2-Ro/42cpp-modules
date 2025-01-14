#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "GradeExceptions.hpp"

class Bureaucrat;

class Form {
   private:
    const std::string  name_;
    bool               is_signed_;
    const unsigned int grade_to_sign_;
    const unsigned int grade_to_execute_;

   public:
    Form();
    Form(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string  getName() const;
    bool         getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const Form& form);
