#pragma once
#include "AAnalyser.h"
#include <FlexLexer.h>
#include <sstream>
class FLexAnalyser : public AAnalyser {
    yyFlexLexer lexer;
    public:
    FLexAnalyser(std::vector<std::string> & strMass) : AAnalyser() {
        for (auto &s : strMass) stream << s << "\n";
    }
    void check();
    void checkManyString(std::vector<std::string> &) override;
    std::stringstream stream;
    void check2(std::string &str);

};