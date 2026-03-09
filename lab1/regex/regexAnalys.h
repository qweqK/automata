#pragma once
#include <string>
#include <vector>
#include "../analyser/AAnalyser.h"
#include <regex>
class RegexAnalys: public AAnalyser  {
    std::regex regex;
    // std::regex name;
    // std::regex opt;
    // std::regex arg;
    // std::regex space;
    public:
    RegexAnalys() : regex("(^[a-zA-Z]+)(?:\\s+-[a-zA-Z]+)*(?:\\s+[a-zA-Z]+)*\\s*$" ,
        std::regex::optimize){}/*, name("^[a-zA-Z]+$",std::regex::optimize),
    opt("^-[a-zA-Z]+$",std::regex::optimize),
    arg("^[a-zA-Z]+$", std::regex::optimize),
    space("\\s+")  { }*/

    void chekString(std::string & str);
    void checkManyString (std::vector<std::string> &) override;
    void chekString2(std::string &str);
};
