#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        std::string input(argv[1]);
        for (int i = 1; i < argc; i++) {
            for (const char *p = argv[i]; *p; ++p) {
                std::cout << static_cast<char>(std::toupper(*p));
            }
        }
    }
    std::cout << std::endl;
    return 0;
}
