#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Expected exactly 1 argument but got: " << argc - 1 << std::endl;
        return 1;
    }
    BitcoinExchange bitcoinExchange;
    if (!bitcoinExchange.load_data_from_csv("data.csv")) {
        return 1;
    }
    if (!bitcoinExchange.calculate_all_values(argv[1])) {
        return 1;
    }
    return 0;
}