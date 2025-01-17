#pragma once

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
    const std::string target_;

   public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const& executor) const;
};