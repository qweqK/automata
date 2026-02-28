#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

class writerReader {
    std::string _read;
    std::string _writeRes;
    std::string _writeState;
    std::vector<std::string> _lines;
    public:
    writerReader(std::string &readd, std::string &writeeRes, std::string &writeState) : _read(std::move(readd)), _writeRes(std::move(writeeRes)), _writeState(std::move(writeState)) {}

    std::vector<std::string> &getLines() {return _lines;}
    void writeRes(const std::vector<bool> & res);
    void writeState(const std::unordered_map<std::string,int> &state);
    void read();

};
