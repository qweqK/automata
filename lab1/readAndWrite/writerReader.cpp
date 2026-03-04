#include "writerReader.h"

#include <iostream>

void writerReader::read() {
    std::ifstream in;
    in.open(_read);
    if (in.is_open()) {
        std::string st;
        while (getline(in,st)) {
            _lines.emplace_back(st);
        }
    }
    in.close();
}

void writerReader::writeState(const std::unordered_map<std::string,int> &res) {
    std::ofstream out;
       out.open(_writeState);
        if (out.is_open()) {
            for (auto &i : res) {
                out << i.first << " " << i.second << std::endl;
            }
        }
       out.close();
}

void writerReader::writeRes(const std::vector<bool> & res) {
    std::ofstream out;
    out.open(_writeRes);
    if (out.is_open()) {
        for (auto i : res) {
            if (i==true) out << "good" << std::endl;
            else out << "bad" << std::endl;
        }
    }
    out.close();
}

void writerReader::writeTime(std::chrono::duration<double> & time) {
    std::ofstream out(_writeTimeRes, std::ios::app);
    if (out.is_open()) {
        out << time.count() << std::endl;
    }
    else throw std::runtime_error("Error writing nameResTimeFILE");
}




