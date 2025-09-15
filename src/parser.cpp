// Basic parser skeleton for SimpleLang
#include <iostream>
#include <vector>
#include <string>
#include "lexer.cpp"
using namespace std;

class Parser {
    Lexer &lexer;
    Token current;
public:
    Parser(Lexer &l) : lexer(l) {
        current = lexer.getNextToken();
    }
    void consume(TokenType t) {
        if (current.type == t) current = lexer.getNextToken();
        else cerr << "Syntax error: expected token " << t << " but got " << current.text << endl;
    }
    void parse() {
        while (current.type != TOKEN_EOF) {
            cout << "Parsed token: " << current.text << endl;
            current = lexer.getNextToken();
        }
    }
};
