#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_ASSIGN,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_IF, TOKEN_EQUAL,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_SEMICOLON, TOKEN_EOF, TOKEN_UNKNOWN
};

struct Token {
    TokenType type;
    string text;
};

class Lexer {
    ifstream file;
public:
    Lexer(const string &filename) {
        file.open(filename);
    }

    Token getNextToken() {
        char c;
        while (file.get(c)) {
            if (isspace(c)) continue;
            if (isalpha(c)) {
                string text(1, c);
                while (file.get(c) && isalnum(c)) text += c;
                if (!file.eof()) file.unget();
                if (text == "int") return {TOKEN_INT, text};
                if (text == "if") return {TOKEN_IF, text};
                return {TOKEN_IDENTIFIER, text};
            }
            if (isdigit(c)) {
                string text(1, c);
                while (file.get(c) && isdigit(c)) text += c;
                if (!file.eof()) file.unget();
                return {TOKEN_NUMBER, text};
            }
            switch (c) {
                case '=': return {TOKEN_ASSIGN, "="};
                case '+': return {TOKEN_PLUS, "+"};
                case '-': return {TOKEN_MINUS, "-"};
                case '{': return {TOKEN_LBRACE, "{"};
                case '}': return {TOKEN_RBRACE, "}"};
                case ';': return {TOKEN_SEMICOLON, ";"};
            }
            return {TOKEN_UNKNOWN, string(1, c)};
        }
        return {TOKEN_EOF, ""};
    }
};
