#include <iostream>
#include "smc/src/Analyser.h"
int main() {
    std::string str = "qwe -we r";
    std::string str2 = "qwe -wq";
    std::string str3 = "qr -";

    Analyser a;
    a.chekString(str);
    a.chekString(str2);
    a.chekString(str3);
    a.printRes(std::cout);
    a.printCom(std::cout);
}