#include <iostream>
#include "../utils/FileReader.h"

int main() {
    FileReader fp("Makefile");
    std::string result= fp.readFile();

    std::cout << result << std::endl;

    return 0;
}
