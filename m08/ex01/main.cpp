#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(2147483647);
    sp.addNumber(-2147483647);
    sp.addNumber(20);
    sp.addNumber(10);
    //sp.addNumber(13);
    //try {
        //sp.addNumber(11);
    //}
    //catch(const std::exception& e) {
        //std::cerr << e.what() << '\n';
    //}
    sp.print();
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    return 0;
}