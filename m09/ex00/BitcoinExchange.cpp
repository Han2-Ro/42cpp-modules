#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
    this->exchange_rates = other.exchange_rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

std::string trim(const std::string& str) {
    size_t first = 0;
    while (first < str.size() && std::isspace(str[first])) {
        ++first;
    }
    size_t last = str.size();
    while (last > first && std::isspace(str[last - 1])) {
        --last;
    }
    return str.substr(first, last - first);
}

bool foreach_row_from_csv() {
    return true;
}

bool BitcoinExchange::load_data_from_csv(std::string filename) {
    std::ifstream fs(filename.c_str());
    std::string   line;
    std::string   date;
    std::string   str_exchange_rate;
    char*         endptr;

    if (!fs.is_open()) {
        return false;
    }
    while (getline(fs, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, str_exchange_rate, ',');
        float f_exchang_rate = std::strtof(str_exchange_rate.c_str(), &endptr);
        //TODO: validation
        if (*endptr != '\0') {
            std::cout << "failed to convert to float: " << str_exchange_rate << std::endl;
            continue;
        }
        exchange_rates[date] = f_exchang_rate;
    }
    std::cout << exchange_rates.at("2019-01-01") << std::endl;
    return true;
}
