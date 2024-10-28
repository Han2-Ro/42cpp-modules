#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    Contact(std::string, std::string, std::string, std::string, std::string);
    ~Contact();
    void display();
    void display_short();
    void set_values();
};

#endif
