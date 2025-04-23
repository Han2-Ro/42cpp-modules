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

bool BitcoinExchange::add_exchange_rate(std::string date, float rate) {
    exchange_rates[date] = rate;
    return true;
}

bool BitcoinExchange::foreach_row_in_csv(std::string filename, bool (BitcoinExchange::*func)(std::string, float), char seperator) {
    std::ifstream fs(filename.c_str());
    std::string   line;
    std::string   date;
    std::string   str_value;
    char*         endptr;

    if (!fs.is_open()) {
        return false;
    }
    // Skip the first line (header)
    // TODO: validate header
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, seperator);
        std::getline(ss, str_value, seperator);
        date = trim(date);
        str_value = trim(str_value);
        float f_value = std::strtof(str_value.c_str(), &endptr);
        // TODO: validation
        if (*endptr != '\0') {
            std::cerr << "failed to convert to float: " << str_value << std::endl;
            std::cerr << "Skipping" << std::endl;
            continue;
        }
        (this->*func)(date, f_value);
    }
    return true;
}

bool BitcoinExchange::load_data_from_csv(std::string filename) {
    foreach_row_in_csv(filename, &BitcoinExchange::add_exchange_rate);
    std::cout << exchange_rates.at("2019-01-01") << std::endl;
    return true;
}

bool BitcoinExchange::calculate_value(std::string date, float in_value) {
    std::cout << date << ':' << in_value << std::endl;
    return true;
}

void BitcoinExchange::calculate_all_values(std::string filename) {
    foreach_row_in_csv(filename, &BitcoinExchange::calculate_value, '|');
}