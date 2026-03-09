
#include <iostream>
#include <string>
#include "generat.h"
int main () {
    Generator g(22000, 10000, "22k.txt");
    std::string s;
    g.genFile();

}
