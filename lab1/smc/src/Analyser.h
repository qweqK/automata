
#pragma once
#include <map>
#include <iostream>
#include <vector>

#include "Analyser_sm.h"

class Analyser {
    bool _beforeArg;
    std::string bufNameCom;
    std::map<std::string, int> _strMap;
    std::vector<bool> _massRes;
    AnalyserContext _fsm;


public:
    bool isGood;
    Analyser() : _beforeArg(true), isGood(false), bufNameCom() , _strMap(), _massRes(), _fsm(*this){}
    void setAfterArg() { _beforeArg = false; }
    [[nodiscard]] bool isBeforeArg() const { return _beforeArg; }
    void resetStateStr() {_beforeArg = true;}
    void setGood() { isGood = true; }
    void chekString(std::string & str);
    void setBad() {isGood = false; }
    void boof(char c) {bufNameCom.push_back(c);}
    void countUsesCom() {_strMap[bufNameCom]++;}
    void resetBuffer() {bufNameCom.clear();}
    void massPlus(bool s){ _massRes.push_back(s);}
    void printCom(std::ostream &os) {for (auto & n: _strMap) os << n.first << " " << n.second<<std::endl;}
    void printRes(std::ostream &os) { for (auto b : _massRes) if (b) os << "good" << std::endl; else os << "bad" << std::endl; }



};
