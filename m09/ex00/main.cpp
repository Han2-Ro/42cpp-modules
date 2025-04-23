#include "BitcoinExchange.hpp"

int main() {
    BitcoinExchange bitcoinExchange;
    if (!bitcoinExchange.load_data_from_csv("data.csv")) {
        return 1;
    }
    bitcoinExchange.calculate_all_values("input.txt");
    return 0;
}