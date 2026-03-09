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

/*void RegexAnalys::chekString2(std::string &str) {
    std::sregex_token_iterator it(str.begin(), str.end(), space, -1);
    std::sregex_token_iterator stop;
    if (it == stop) return;
    std::smatch m;
    if (!std::regex_match(it->str(),  name)) {_massRes.push_back(false); return;}
    std::string buf = it->str();
    it++;
    bool afterArgs = false;
    for (; it!= stop; ++it) {
        std::string word = it->str();
        if (word.empty()) continue;
        if(!afterArgs) {
            if (std::regex_match(word, m, opt)) continue;
            else if (std::regex_match(word, m, arg)) {afterArgs = true;}
            else {_massRes.push_back(false); return;}
        }
        else {
            if (!std::regex_match(word, m, arg)) {_massRes.push_back(false); return;}
        }
    }
    _massRes.push_back(true);
    _strMap[buf]++;
}*/