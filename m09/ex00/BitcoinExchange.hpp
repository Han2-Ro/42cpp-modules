#pragma once

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
   private:
    std::map<std::string, float> exchange_rates;
    bool                         add_exchange_rate(std::string date, float rate);
    bool                         foreach_row_from_csv(std::string filename, bool (BitcoinExchange::*func)(std::string, float));

   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    bool load_data_from_csv(std::string filename);
};
