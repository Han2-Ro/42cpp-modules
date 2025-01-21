#pragma once

#include <stdint.h>

#include <string>

struct Data {
    std::string name;
    int         age;

    Data(std::string name, int age) : name(name), age(age) {}
};

class Serializer {
   private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

   public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};
