#include "lexico.h"
#include "mainwindow.h"
#include "QtDebug"
Lexico::Lexico()
{

}

Lexico::Lexico(string entrada){
    this->entrada = entrada+'$';
    this->length = entrada.length();
}

vector<pair<string,int>>  Lexico::read(){
    vector<pair<string,int>> ans;
    bool canBeString = false;
    string canBe = "\"";
    string token = "";
    int i=0;
    for(auto e:this->entrada){//Here I read the string and then separate it into different tokens
        if(canBeString){//If a " has been detected I check if it is a complete string if it is not I take it as an error
            if(e=='"'){
                canBeString = false;
                ans.push_back({token,3});
                token="";
            }else if(e=='$'){
                canBeString = false;
                ans.push_back({token,-1});
                token="";
            }else{
                token+=e;
            }
        }else if(token == canBe){
            canBeString=true;
            token="";
            token+=e;
        }else if(e==';'){
            checkToken(token);
            string aux=""; aux+=e;
            checkToken(aux);
            token="";
        }else if((e=='$' && token != "") || (isWhitespace(e) && token != "")){
            int code = checkToken(token);
            ans.push_back({token, code});
            token="";
        }else if(isWhitespace(e) && token == ""){
            continue;
        }else{
            token+=e;
        }
        if(this->reserved.count(token)!=0){//Here I check if there is a valid token even if a blank space has not been found
            ans.push_back({token,this->reserved[token]});
            token="";
        }
        i++;
    }
    return ans;
}

int Lexico::checkToken(string token){
    int code;
    if(this->reserved.count(token) !=0){
        code=this->reserved[token];
    }else if(isIdentifier(token)){
        code = 0;
    }else if(isInteger(token)){
        code=1;
    }else if(isReal(token)){
        code=2;
    }else if(isString(token)){
        return 3;
    }else{
        code=-1;
    }
    return code;
}

bool Lexico::isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool Lexico::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Lexico::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Lexico::isIdentifier(const string& token) {
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

bool Lexico::isInteger(const string& token) {
    for (char c : token) {
        if (!isDigit(c)) {
            return false;
        }
    }
    return true;
}

bool Lexico::isReal(const string& token) {
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

bool Lexico::isString(const string & token){
    if(token[0] == '"' && token[token.length()-1] == '"'){return true;}
    else{return false;}
}
