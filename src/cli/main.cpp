#include <iostream>
#include "../utils/FileReader.h"
#include "../infrastructures/services/XmlParserService.h"

int main() {
    FileReader fp("../ressources/xml/file.xml");
    std::string result = fp.readFile();

    XmlParserService::xmlParser(result);


    return 0;
}
