#include <iostream>

#include "Serializer.hpp"

int main() {
    {
        uintptr_t raw = Serializer::serialize(new Data("Arthur Dent", 42));
        Data*     data_out = Serializer::deserialize(raw);
        std::cout << "Name: " << data_out->name << std::endl;
        std::cout << "Age: " << data_out->age << std::endl;
        delete data_out;
    }
    {
        Data      data_in = Data("Marvin", 100);
        uintptr_t raw = Serializer::serialize(&data_in);
        Data*     data_out = Serializer::deserialize(raw);
        std::cout << "Name: " << data_out->name << std::endl;
        std::cout << "Age: " << data_out->age << std::endl;
        return 0;
    }
}