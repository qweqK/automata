#include "generat.h"

#include <ostream>
#include <stdexcept>
#include <iostream>
#include <fstream>

 std::string Generator::generateSubstr(std::ostream &os, int numSymb) {
    std::uniform_int_distribution<> dis(0, static_cast<int>(_alpha.size()) - 1);
     std::string res;
    for (int i = 0; i < numSymb; i++) {
         res.push_back(_alpha[dis(_generator)]);
    }
     return res;
}

 std::string Generator::generateString(std::ostream &os) {
     int curLen = _numberOfSymbol;
     int numOpt = 0;
     if (curLen<50) {return generateSubstr(os, _numberOfSymbol);}
     std::uniform_int_distribution<> charDis(0, curLen/10);
     std::uniform_int_distribution<> lengthOpt(2, 15 );
     std::string res=generateSubstr(os, 4);
     curLen -=4;

     while ((charDis(_generator) < curLen-numOpt*12) &&  curLen>0) {
         res.append(" -");
         int l = lengthOpt(_generator);
         res.append(generateSubstr(os,l));
         numOpt++;
         curLen -= l;
     }

     while (curLen>0) {
         res.push_back(' ');
         int l = lengthOpt(_generator);
         res.append(generateSubstr(os, l));
         curLen -= l;
     }
    return  res;

}

void Generator::genFile() {
     std::ofstream out;
     std::uniform_int_distribution<> charDis(1,3);
     out.open(_fileResName.c_str());
     if (!out.is_open()) throw std::runtime_error("Can't open file");
     for (int i=0; i<_numberOfString; i++) {
         if (charDis(_generator)==1) out << mutateString(generateString(out)) << std::endl;
         else out << generateString(out) << std::endl;
     }

     out.close();
 }



std::string Generator::mutateString(std::string str) {
     std::uniform_int_distribution<> charDis(1,3);
     std::uniform_int_distribution<> LenStr(1,str.length()-1);
     int a =charDis(_generator);
     std::shuffle(str.begin(), str.end(), _generator);
     return str;
 }
