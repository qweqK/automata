#include "regexAnalys.h"

#include <iostream>
#include <regex>

void RegexAnalys::chekString(std::string &str) {
    std::smatch m;
    if (std::regex_match(str, m, regex)) {
        _strMap[m[1]]++;
        _massRes.push_back(true);
    }
    else {
        _massRes.push_back(false);
    }

}

void RegexAnalys::checkManyString(std::vector<std::string> & lines) {
    for (auto &l :lines) {
        chekString(l);
    }
}
