#pragma once

#include <fstream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   private:
    const std::string target_;

   public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};
