
#pragma once
#include <map>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../analyser/AAnalyser.h"
#include "Analyser_sm.h"

class SMCAnalyser : public AAnalyser {
    std::string bufNameCom;
    AnalyserContext _fsm;
    bool isGood;

public:
    bool takeGood() {return isGood;}
    SMCAnalyser() :  isGood(true), bufNameCom() , _fsm(*this), AAnalyser(){}
    void setGood() { isGood = true; }
    void resetBuffer() {bufNameCom.clear();}
    void setBad() {isGood = false; }
    void boof(char c) {bufNameCom.push_back(c);}


    void chekString(std::string & str);
    void countUsesCom()  {_strMap[bufNameCom]++;}
    void massPlus(bool s)  { _massRes.push_back(s);}
    void checkManyString (std::vector<std::string> &) override;



};
