#include <ctime>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: expected exactly 1 argument but got: " << argc - 1 << std::endl;
        return 1;
    }
    try {
        BitcoinExchange bitcoinExchange;
        if (!bitcoinExchange.load_data_from_csv("data.csv")) {
            return 1;
        }
        if (!bitcoinExchange.calculate_all_values(argv[1])) {
            return 1;
        }
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}