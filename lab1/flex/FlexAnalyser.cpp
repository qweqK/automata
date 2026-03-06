#include <iostream>
#include <FlexLexer.h>
#include "FlexAnalyser.h"
#include <vector>
#include <sstream>


void FLexAnalyser::check() {
    lexer.switch_streams(&stream, nullptr);

    int t;
    while ((t = lexer.yylex()) != 0) {
        if (t == 1) {
            _strMap[lexer.YYText()]++;
            _massRes.push_back(true);
        }
        else _massRes.push_back(false);
    }
}

void FLexAnalyser::checkManyString(std::vector<std::string> &strs) {
    for (auto &s:strs ) {check2(s);}

}


void FLexAnalyser::check2(std::string &str) {
    std::istringstream iss(str+"\n");
    lexer.switch_streams(&iss, nullptr);
    if (lexer.yylex() !=1) {_massRes.push_back(false);  return;}
    std::string buf = lexer.YYText();
    if (lexer.yylex()!=2) {_massRes.push_back(false);  return;}
        _strMap[buf]++;_massRes.push_back(true);
};

void FLexAnalyser::check3(std::string &str) {
    std::istringstream iss(str+"\n");
    lexer.switch_streams(&iss, nullptr);

    if (lexer.yylex() !=1) {_massRes.push_back(false);  return;}
    std::string buf = lexer.YYText();
    if (lexer.yylex()!=2) {_massRes.push_back(false);  return;}
    _strMap[buf]++;_massRes.push_back(true);
};