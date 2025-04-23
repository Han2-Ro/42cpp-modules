#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    this->exchange_rates = other.exchange_rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool is_valid_date(std::string str_date) {
    struct tm tm_before = {};
    strptime(str_date.c_str(), "%Y-%m-%d", &tm_before);
    std::time_t timestamp = std::mktime(&tm_before);
    std::tm     tm_after = *std::localtime(&timestamp);
    char        arr_date_after[11];
    std::strftime(arr_date_after, 11, "%Y-%m-%d", &tm_after);
    std::string str_date_after(arr_date_after);
    return str_date == str_date_after;
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

bool validate_header(std::ifstream& fs, std::string title1, std::string title2, char seperator) {
    std::string line;
    getline(fs, line);
    std::stringstream ss(line);
    std::string       str;
    std::getline(ss, str, seperator);
    if (trim(str) != title1) {
        std::cerr << "Error: expected '" << title1 << "' as column title but got '" << trim(str) << "'" << std::endl;
        return (false);
    }
    std::getline(ss, str, seperator);
    if (trim(str) != title2) {
        std::cerr << "Error: expected '" << title2 << "' as column title but got '" << trim(str) << "'" << std::endl;
        return (false);
    }
    return true;
}

bool BitcoinExchange::foreach_row_in_csv(std::string filename, bool (BitcoinExchange::*func)(std::string, float),
                                         std::string second_title, char seperator) {
    std::ifstream fs(filename.c_str());
    std::string   line;
    char*         endptr;

    if (!fs.is_open()) {
        std::cerr << "Error: could not open file: " << filename << std::endl;
        return false;
    }
    if (!validate_header(fs, "date", second_title, seperator)) {
        return false;
    }
    while (getline(fs, line)) {
        std::string   date("");
        std::string   str_value("");
        std::stringstream ss(line);
        std::getline(ss, date, seperator);
        std::getline(ss, str_value, seperator);
        date = trim(date);
        if (!is_valid_date(date)) {
            std::cerr << "Error: invalid date: " << date << std::endl;
            continue;
        }
        str_value = trim(str_value);
        if (str_value.size() == 0) {
            std::cerr << "Error: bad input" << std::endl;
            continue;
        }
        float f_value = std::strtof(str_value.c_str(), &endptr);
        // TODO: validation and check empty string
        if (*endptr != '\0') {
            std::cerr << "Error: failed to convert to float: " << str_value << std::endl;
            continue;
        }
        (this->*func)(date, f_value);
    }
    return true;
}

bool BitcoinExchange::load_data_from_csv(std::string filename) {
    return foreach_row_in_csv(filename, &BitcoinExchange::add_exchange_rate, "exchange_rate");
}

bool BitcoinExchange::calculate_value(std::string date, float in_value) {
    std::map<std::string, float>::iterator iter = exchange_rates.upper_bound(date);
    if (iter == exchange_rates.begin()) {
        std::cerr << "Error: date out of range: " << date << std::endl;
        return false;
    }
    --iter;
    float result = in_value * iter->second;
    std::cout << date << " => " << in_value << " = " << result << std::endl;
    return true;
}

bool BitcoinExchange::calculate_all_values(std::string filename) {
    return foreach_row_in_csv(filename, &BitcoinExchange::calculate_value, "value", '|');
}
