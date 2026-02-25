#include "Analyser.h"
#include "cctype"
void Analyser::chekString(std::string &str ) {
    for (auto & c : str) {
        if (isalpha(c)) {
            std::cout << 1 <<std::endl;
            _fsm.letter(c);
        }
        else if (c== '-') {
            std::cout << 2 <<std::endl;
            _fsm.hyphen();

        }
        else if (c == ' ') {
            std::cout << 3 <<std::endl;
            _fsm.space();


        }
        /*else if (isdigit(c)) {
            std::cout << 4 <<std::endl;
            _fsm.number(static_cast<int>(c)-48);

        }*/
        else {
            std::cout << 5 <<std::endl;
            _fsm.unknown();
        }
    }
    _fsm.EOS();
    _fsm.nextString();
    massPlus(isGood);

}



