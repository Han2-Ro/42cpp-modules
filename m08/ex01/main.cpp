#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try
    {
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sp.print();
    return 0;
}