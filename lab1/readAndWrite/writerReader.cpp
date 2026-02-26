#include "writerReader.h"

void writerReader::read() {
    if (in.is_open()) {
        std::string st;
        while (getline(in,st)) {
            x.emplace_back(st);
        }
    }
    in.close();
}

void writerReader::write() {

}
