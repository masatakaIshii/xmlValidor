#include <iostream>
#include "../utils/FileReader.h"

int main() {
    FileReader fp("../ressources/xml/file.xml");
    std::string result= fp.readFile();

    std::cout << result << std::endl;

    return 0;
}
