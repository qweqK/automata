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

void FLexAnalyser::checkManyString(std::vector<std::string> &) {
    check();
}
