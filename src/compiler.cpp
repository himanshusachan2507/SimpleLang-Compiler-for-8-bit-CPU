#include "parser.cpp"
#include "codegen.cpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./compiler <source-file>\n";
        return 1;
    }
    string infile = argv[1];
    Lexer lexer(infile);
    Parser parser(lexer);
    parser.parse();
    CodeGen cg;
    cg.generate("output/program.asm");
    cout << "Compilation finished. Assembly in output/program.asm\n";
    return 0;
}
