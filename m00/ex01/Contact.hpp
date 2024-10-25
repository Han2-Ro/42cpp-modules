#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
private:
    char *first_name;
    char *last_name;
    char *nickname;
    char *phone_number;
    char *darkest_secret;

public:
    Contact();
    Contact(char*, char*, char*, char*, char*);
    ~Contact();
    void display();
    void display_header();
};

#endif
