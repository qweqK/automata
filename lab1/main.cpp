#include <FlexLexer.h>
#include <iostream>
#include "smc/Analyser.h"
#include <fstream>
#include <numeric>

#include "FlexAnalyser.h"
#include "regexAnalys.h"
#include "writerReader.h"

int main(int argc, char **argv) {
    try {
        if (argc < 3) {
            throw std::invalid_argument("Usage: oper_mod(-f, -s, -r) ,-intput_file.txt, time_res_file.txt, number_of_exp");
        }
        std::vector<std::string> args(argv, argv+argc);
        writerReader reader(args[2], "outputState.txt", "outputRes.txt", args[3] );
        reader.read();
        std::vector<std::chrono::duration<double>> times;

        auto lines = reader.getLines();

        for (int i = 1; i < 11; i++) {
            std::unique_ptr<AAnalyser> a;
            if (args[1] == "f") {
                a = std::make_unique<FLexAnalyser>(lines);
            }
            else if (args[1] == "s") {
                a = std::make_unique<SMCAnalyser>();

            }
            else if (args[1] == "r") {
                a= std::make_unique<RegexAnalys>();
            }
            else  throw std::invalid_argument("Unknown argument");
            auto start = std::chrono::steady_clock::now();
            a->checkManyString(lines);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double>diff = end - start;
            times.push_back(diff);
            reader.writeState(a->getStateMap());
            reader.writeRes(a->getMassResult());
            std::cout << diff.count() << std::endl;
        }

        auto res = std::accumulate(times.begin(), times.end(), std::chrono::duration<double>(0));
        auto sred_time = res/times.size();
        reader.writeTime( sred_time);
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


}