//
// Created by masat on 01/11/2020.
//

#include "FileReader.h"
#include <fstream>

using namespace std;

FileReader::FileReader(std::string filePath): filePath(std::move(filePath)) {
}
FileReader::~FileReader() {
    filePath.erase();
}

string FileReader::readFile() const {
    string result;
    ifstream buffer(filePath);
    if (buffer) {
        buffer.seekg(0, std::ios::end);
        result.reserve(buffer.tellg());
        buffer.seekg(0, std::ios::beg);
        result.assign(std::istreambuf_iterator<char>(buffer), std::istreambuf_iterator<char>());

        buffer.close();
    } else {
        cerr << "Problem open '" + filePath + "' file";
    }

    return result;
}


