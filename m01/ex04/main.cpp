#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    std::string content;

    if (argc != 4) {
        std::cerr << "Expected three arguments: filename, search string and replace string" << std::endl;
        return 1;
    }

    std::string inFilename = argv[1];
    std::string outFilename = inFilename + ".replace";

    std::ifstream inFile(inFilename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Couldn't open " << inFilename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    content = buffer.str();
    inFile.close();

    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Couldn't open " << outFilename << std::endl;
        return 1;
    }
    outFile << content;
    outFile.close();
}
