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

static bool isChar(const std::string& input) {
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

static bool isInt(const std::string& input) {
    char* end;
    long  val = std::strtol(input.c_str(), &end, 10);
    return *end == '\0' && val >= std::numeric_limits<int>::min() &&
           val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& input) {
    if (input == "nanf" || input == "+inff" || input == "-inff") {
        return true;
    }
    if (input[input.length() - 1] != 'f') {
        return false;
    }
    char* end;
    std::strtof(input.c_str(), &end);
    return *end == 'f';
}

static bool isDouble(const std::string& input) {
    if (input == "nan" || input == "+inf" || input == "-inf") {
        return true;
    }
    char* end;
    std::strtod(input.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& input) {
    // Print char
    std::cout << "char: ";
    try {
        if (isChar(input)) {
            char c = input[1];
            if (std::isprint(c)) {
                std::cout << "'" << c << "'" << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
        } else if (isInt(input)) {
            int val = std::atoi(input.c_str());
            if (val >= 0 && val <= 127 && std::isprint(val)) {
                std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
            } else if (val >= 0 && val <= 127) {
                std::cout << "Non displayable" << std::endl;
            } else {
                std::cout << "impossible" << std::endl;
            }
        } else if (isFloat(input) || isDouble(input)) {
            double val = std::strtod(input.c_str(), NULL);
            if (std::isnan(val) || std::isinf(val)) {
                std::cout << "impossible" << std::endl;
            } else if (val >= 0 && val <= 127 && std::isprint(static_cast<int>(val))) {
                std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
            } else if (val >= 0 && val <= 127) {
                std::cout << "Non displayable" << std::endl;
            } else {
                std::cout << "impossible" << std::endl;
            }
        } else {
            std::cout << "impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Print int
    std::cout << "int: ";
    try {
        if (isChar(input)) {
            std::cout << static_cast<int>(input[1]) << std::endl;
        } else if (isInt(input)) {
            std::cout << std::atoi(input.c_str()) << std::endl;
        } else if (isFloat(input) || isDouble(input)) {
            double val = std::strtod(input.c_str(), NULL);
            if (std::isnan(val) || std::isinf(val) || val > std::numeric_limits<int>::max() ||
                val < std::numeric_limits<int>::min()) {
                std::cout << "impossible" << std::endl;
            } else {
                std::cout << static_cast<int>(val) << std::endl;
            }
        } else {
            std::cout << "impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Print float
    std::cout << "float: ";
    try {
        if (isChar(input)) {
            std::cout << static_cast<float>(input[1]) << ".0f" << std::endl;
        } else if (isInt(input)) {
            std::cout << static_cast<float>(std::atoi(input.c_str())) << ".0f" << std::endl;
        } else if (isFloat(input)) {
            if (input == "nanf") {
                std::cout << "nanf" << std::endl;
            } else if (input == "+inff") {
                std::cout << "+inff" << std::endl;
            } else if (input == "-inff") {
                std::cout << "-inff" << std::endl;
            } else {
                float val = std::strtof(input.c_str(), NULL);
                std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
            }
        } else if (isDouble(input)) {
            if (input == "nan") {
                std::cout << "nanf" << std::endl;
            } else if (input == "+inf") {
                std::cout << "+inff" << std::endl;
            } else if (input == "-inf") {
                std::cout << "-inff" << std::endl;
            } else {
                double val = std::strtod(input.c_str(), NULL);
                std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f"
                          << std::endl;
            }
        } else {
            std::cout << "impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Print double
    std::cout << "double: ";
    try {
        if (isChar(input)) {
            std::cout << static_cast<double>(input[1]) << ".0" << std::endl;
        } else if (isInt(input)) {
            std::cout << static_cast<double>(std::atoi(input.c_str())) << ".0" << std::endl;
        } else if (isFloat(input)) {
            if (input == "nanf") {
                std::cout << "nan" << std::endl;
            } else if (input == "+inff") {
                std::cout << "+inf" << std::endl;
            } else if (input == "-inff") {
                std::cout << "-inf" << std::endl;
            } else {
                float val = std::strtof(input.c_str(), NULL);
                std::cout << std::fixed << std::setprecision(1) << static_cast<double>(val)
                          << std::endl;
            }
        } else if (isDouble(input)) {
            if (input == "nan") {
                std::cout << "nan" << std::endl;
            } else if (input == "+inf") {
                std::cout << "+inf" << std::endl;
            } else if (input == "-inf") {
                std::cout << "-inf" << std::endl;
            } else {
                double val = std::strtod(input.c_str(), NULL);
                std::cout << std::fixed << std::setprecision(1) << val << std::endl;
            }
        } else {
            std::cout << "impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }
}