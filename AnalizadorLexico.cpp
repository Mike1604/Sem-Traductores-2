#include <bits/stdc++.h >

using namespace std;

map<string, string> reserved = {
    {"+", "opSuma"},
    {"-", "opSuma"},
    {"int", "tipo"},
    {"float", "tipo"},
    {"void", "tipo"},
    {"*", "opMul"},
    {"/", "opMul"},
    {"<", "opRelac"},
    {"<=", "opRelac"},
    {">", "opRelac"},
    {">=", "opRelac"},
    {"||", "opOr"},
    {"&&", "opAnd"},
};

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isIdentifier(const string& token) {
    if (isLetter(token[0])) {
        for (char c : token) {
            if (!(isLetter(c) || isDigit(c))) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isInteger(const string& token) {
    for (char c : token) {
        if (!isDigit(c)) {
            return false;
        }
    }
    return true;
}

bool isReal(const string& token) {
    bool hasDot = false;
    for (char c : token) {
        if (c == '.') {
            if (hasDot) {
                return false; // More than one dot
            }
            hasDot = true;
        } else if (!isDigit(c)) {
            return false;
        }
    }
    return hasDot;
}

void check(vector<pair<string, string>>& tokens, string token) {
    if (reserved.count(token) != 0) {
        tokens.push_back({token, reserved[token]});
    } else if (isIdentifier(token)) {
        tokens.push_back({token, "identificador"});
    } else if (isInteger(token)) {
        tokens.push_back({token, "entero"});
    } else if (isReal(token)) {
        tokens.push_back({token, "real"});
    } else {
        tokens.push_back({token, "Not recognized"});
    }
}

int main() {
    int buc = 0;
    vector<pair<string, string>> tokens;
    
    while (buc == 0) {
        string input, token;
        cout << "Introduce la cadena a evaluar: ";
        getline(cin, input);
        cout << endl;
        
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                check(tokens, token);
                token = "";
            } else {
                token += input[i];
            }
        }
        
        check(tokens, token);
        
        for (auto e : tokens) {
            cout << "Token: " << e.first << " Tipo: " << e.second << endl;
        }
        
        tokens.clear(); // Limpiar el vector de tokens para la siguiente iteración
    }

    return 0;
}
