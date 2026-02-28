#include <iostream>
#include "smc/src/Analyser.h"
#include <fstream>
#include "writerReader.h"
int main() {
//     Analyser a;
//     std::ifstream in("qweq.txt");
//     std::vector<std::string> x;
//     if (in.is_open()) {
//         std::string st;
//         while (getline(in,st)) {
//             x.emplace_back(st);
//         }
//     }
//     in.close();
//
//     for (auto &s : x) {
//         a.chekString(s);
//     }
//
//
//     std::ofstream out;
//     out.open("output.txt");
//     if (out.is_open()) {
//         std::cout << "норм откр" << std::endl;
//         a.printRes(out);
//         a.printCom(out);
//     }
//     out.close();
    std::string fileData;
    std::string fileResOut;
    std::string fileStateOut;

    std::cout << "name file which you want check: " << std::endl;
    std::cin >> fileData;
    std::cout << "name file fot res: " << std::endl;
    std::cin >> fileResOut;
    std::cout << "name file fot state: " << std::endl;
    std::cin >> fileStateOut;
    try {
        writerReader reader(fileData, fileResOut, fileStateOut);
        reader.read();
        Analyser analyserSMC;
        analyserSMC.checkManyString(reader.getLines());
        reader.writeRes(analyserSMC.getMassResult());
        reader.writeState(analyserSMC.getStateMap());
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}