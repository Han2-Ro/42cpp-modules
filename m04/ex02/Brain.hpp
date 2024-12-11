#pragma once

#include <string>

class Brain {
   private:
    static const unsigned int size = 100;
    std::string               ideas[size];

   public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    std::string getIdea(const unsigned int& index) const;
    void        setIdea(const unsigned int& index, std::string idea);
};
