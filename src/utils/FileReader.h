//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_FILEREADER_H
#define XMLVALIDOR_FILEREADER_H

#include <iostream>

class FileReader {
public:
    explicit FileReader(std::string);
    ~FileReader();
    std::string readFile() const;
private:
    std::string filePath;
};

#endif //XMLVALIDOR_FILEREADER_H
