#pragma once
#include <string>
#include <random>

class Generator {
    int _numberOfSymbol;
    int _numberOfString;
    std::string _fileResName;
    std::random_device _rd;
    std::mt19937 _generator;
    const std::string _alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public:
    std::string generateSubstr(std::ostream &os, int numSymb);
    Generator(int NOSymb, int NOString, std::string fileResName) : _numberOfSymbol(NOSymb), _numberOfString(NOString), _fileResName(std::move(fileResName)), _generator(_rd()) {}
    std::string generateString(std::ostream &os);
    void genFile();
    std::string mutateString(std::string str);

};