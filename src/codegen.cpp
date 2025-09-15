// Dummy code generator for SimpleLang -> 8-bit assembly
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CodeGen {
public:
    void generate(const string &outfile) {
        ofstream out(outfile);
        out << "; Assembly generated for SimpleLang\n";
        out << "MOV A, 10\n";
        out << "MOV B, 20\n";
        out << "ADD A, B\n";
        out << "HLT\n";
        out.close();
    }
};
