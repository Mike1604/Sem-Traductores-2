#ifndef LEXICO_H
#define LEXICO_H
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Lexico
{
private:
    string entrada;
    int length;
    map<string, int> reserved = {
        {"int", 4},
        {"float", 4},
        {"void", 4},
        {"+", 5},
        {"-", 5},
        {"*", 6},
        {"/", 6},
        {"<", 7},
        {"<=", 7},
        {">", 7},
        {">=", 7},
        {"||", 8},
        {"&&", 9},
        {"!", 10},
        {"==", 11},
        {"!=", 11},
        {";", 12},
        {",", 13},
        {"(", 14},
        {")", 15},
        {"{", 16},
        {"}", 17},
        {"=", 18},
        {"if", 19},
        {"while", 20},
        {"return", 21},
        {"else", 22},
        {"$", 23},
    };
public:
    Lexico();
    Lexico(string entrada);
    vector<pair<string,int>> read();
    int checkToken(string);
    bool isDigit(char);
    bool isLetter(char);
    bool isWhitespace(char);
    bool isIdentifier(const string&);
    bool isInteger(const string&);
    bool isReal(const string&);
    bool isString(const string&);
};

#endif // LEXICO_H
