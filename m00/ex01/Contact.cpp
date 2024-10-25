#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(char* first_name, char* last_name, char* nickname, char* number, char* darkest_sceret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = number;
    this->darkest_secret = darkest_sceret;
}

Contact::~Contact()
{
}

void Contact::display() {

}
