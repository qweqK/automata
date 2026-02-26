#include <iostream>
#include "smc/src/Analyser.h"
#include <fstream>
int main() {
    Analyser a;
    std::ifstream in("input.txt");
    std::vector<std::string> x;
    if (in.is_open()) {
        std::string st;
        while (getline(in,st)) {
            x.emplace_back(st);
        }
    }
    in.close();

    for (auto &s : x) {
        a.chekString(s);
    }


    std::ofstream out;
    out.open("output.txt");
    if (out.is_open()) {
        std::cout << "нори откр" << std::endl;
        a.printRes(out);
        a.printCom(out);
    }
    out.close();
}