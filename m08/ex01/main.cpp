#include "Span.hpp"
#include <vector>

int main() {
    {
        Span sp = Span(7);
        sp.addNumber(2147483647);
        try {
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        sp.addNumber(-2147483647);
        sp.addNumber(20);
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        sp.addNumber(10);
        sp.addNumber(100);
        sp.addNumber(10);
        sp.addNumber(132);
        try {
            sp.addNumber(11);
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        sp.print();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        Span span(1000001);
        std::vector<int> numbersToAdd;
        for (int i = 0; i <= 100000; i++) {
            numbersToAdd.push_back(i*2);
        }
        span.addNumbers(numbersToAdd.begin(), numbersToAdd.end());
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    return 0;
}