#pragma once

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

class BitcoinExchange {
   private:
    std::map<std::string, float> exchange_rates;

   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    bool load_data_from_csv(std::string filename);
};

