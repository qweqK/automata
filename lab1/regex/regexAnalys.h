#pragma once
#include <string>
#include <vector>
#include "../analyser/AAnalyser.h"
#include <regex>
class RegexAnalys: public AAnalyser  {
    std::regex regex;
    public:
    RegexAnalys() : regex("(^[a-zA-Z]+)(?:\\s+-[a-zA-Z]+)*(?:\\s+[a-zA-Z]+)*\\s*$", std::regex::optimize) { }
    void chekString(std::string & str);
    void checkManyString (std::vector<std::string> &) override;
};
