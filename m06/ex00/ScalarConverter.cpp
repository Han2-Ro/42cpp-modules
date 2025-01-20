#include "ScalarConverter.hpp"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

static double getDoubleValue(const std::string& input) {
    if (input == "nan" || input == "nanf") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (input == "+inf" || input == "+inff") {
        return std::numeric_limits<double>::infinity();
    }
    if (input == "-inf" || input == "-inff") {
        return -std::numeric_limits<double>::infinity();
    }

    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        return static_cast<double>(input[1]);
    }

    try {
        char*       endptr;
        std::string tmp = input;
        if (input.length() > 0 && input[input.length() - 1] == 'f') {
            tmp = input.substr(0, input.length() - 1);
        }

        double val = std::strtod(tmp.c_str(), &endptr);
        if (*endptr != '\0') {
            return std::numeric_limits<double>::quiet_NaN();
        }
        return val;
    } catch (...) {
        return std::numeric_limits<double>::quiet_NaN();
    }
}

void ScalarConverter::convert(const std::string& input) {
    double value = getDoubleValue(input);

    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }

    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }

    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+" : "-") << "inff" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f"
                  << std::endl;
    }

    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+" : "-") << "inf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}