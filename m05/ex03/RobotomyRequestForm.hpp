#pragma once

#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    const std::string target_;

   public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};