#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
   private:
    const std::string  name_;
    bool               is_signed_;
    const unsigned int grade_to_sign_;
    const unsigned int grade_to_execute_;

   protected:
    void checkExecutionRequirements(Bureaucrat const& executor) const;

   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    AForm();
    AForm(const std::string& name, unsigned int grade_to_sign, unsigned int grade_to_execute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string  getName() const;
    bool         getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;

    void         beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
