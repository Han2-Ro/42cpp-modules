#pragma once

#include <map>
#include <string>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::map<std::string, void (Harl::*)(void)> dict;
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

