#include "Analyser.h"
#include "cctype"
void SMCAnalyser::chekString(std::string &str ) {
    for (auto & c : str) {
        if (isGood!=true) break;

        if (isalpha(c)) {
            _fsm.letter(c);
        }
        else if (c== '-') {
            _fsm.hyphen();

        }
        else if (c == ' ') {
            _fsm.space();
        }
        else if (c == '\n' || c == '\r') {
            break;
        }
        else {
            _fsm.unknown();
        }

    }
    _fsm.EOS();
    massPlus(takeGood());
    _fsm.nextString();


}


void SMCAnalyser::checkManyString(std::vector<std::string> & lines) {
    for (auto & l : lines) {
        chekString(l);
    }
}



