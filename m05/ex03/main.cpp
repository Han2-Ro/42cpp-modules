#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    AForm* srf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *srf << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *ppf << std::endl;
    AForm* invalid = someRandomIntern.makeForm("invalid form", "Bender");
    std::cout << invalid << std::endl;
    delete rrf;
    delete srf;
    delete ppf;
    return 0;
}
