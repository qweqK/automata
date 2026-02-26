#pragma once
#include <string>

class writerReader {
    std::string _read;
    std::string _write;

    public:
    writerReader(std::string &readd, std::string &writee) : _read(std::move(readd)), _write(std::move(writee)) {}

    void write();
    void read();

};
