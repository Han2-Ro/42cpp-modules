#pragma once
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
   private:
    const std::string name_;
    unsigned int      grade_;
    Bureaucrat();

   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string  getName() const;
    unsigned int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
