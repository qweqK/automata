
#pragma once
#include <map>
#include <iostream>
#include <vector>

#include "Analyser_sm.h"

class Analyser {
    bool _beforeArg;
    int _numOpt;
    int _numArgs;
    int _curNum;
    int _com;

    AnalyserContext _fsm;
    std::string bufNameCom;
    std::map<std::string, int> _strMap;
    std::vector<bool> massRes;


public:
    bool isGood;
    Analyser() : _beforeArg(true), _numOpt(0), _numArgs(0), _curNum(0), isGood(false), _fsm(*this), _strMap(){}
    void increaseOpt() {_numOpt++;}
    void increaseArg() {_numArgs++;}
    void setAfterArg() { _beforeArg = false; }
    //[[nodiscard]] bool isNumEqual() { return _curNum == _numOpt; }
    [[nodiscard]] bool isBeforeArg() const { return _beforeArg; }
    //void numCounter(int num) {_curNum = _curNum*10 + num;}
    void increaseCom() {_com++;}
    void resetStateStr() {_beforeArg = true;}
    void setGood() { isGood = true; }
    void chekString(std::string & str);
    void nameDGB() {std::cout << "name"<< std::endl;}
    void printer(char c) {std::cout << c << std::endl;}
    void setBad() {isGood = false; }
    void boof(char c) {bufNameCom.push_back(c);}
    void countUsesCom() {_strMap[bufNameCom]++;}
    void resetBuffer() {bufNameCom.clear();}
    void printCom(std::ostream &os) {for (auto & n: _strMap) os << n.first << " " << n.second<<std::endl;}
    void massPlus(bool s){ massRes.push_back(s);}
    void printRes(std::ostream &os) { for (auto b : massRes) if (b) os << "good" << std::endl; else os << "bad" << std::endl; }



};
