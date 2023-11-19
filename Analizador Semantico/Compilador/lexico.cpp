#include "lexico.h"
#include "mainwindow.h"
#include "QtDebug"

Lexico::Lexico(string entrada){
    entrada+='$';
    this->entrada = entrada;
    this->length = entrada.length();
}

vector<pair<string,int>>  Lexico::read(){
    vector<pair<string,int>> ans;
    bool canBeString = false;
    bool canBeNumber = false;
    bool skip = false;
    string canBe = "\"";
    string token = "";
    int i=-1;
    for(auto e:this->entrada){//Here I read the string and then separate it into different tokens
        i++;
        string aux=""; aux+=e;
        if(e=='$' && token==""){
            int code = checkToken(aux);
            ans.push_back({token, code});
        }
        if(isWhitespace(e) && !canBeString){continue;};
        if(canBeNumber){
            QString contenido = QString::fromStdString(token);
            string a ="";
            if(!isDigit(e) && isLetter(e) && !isWhitespace(e)){
                canBeNumber=false;
            }
            else if(!isDigit(e) && !isLetter(e) && !isWhitespace(e) && this->reserved.count(a+e) != 0){
                canBeNumber=false;
                int code = checkToken(token);
                ans.push_back({token, code});
                token="";
            }
        }
        if(canBeString){//If a " has been detected I check if it is a complete string if it is not I take it as an error
            if(e=='"'){
                canBeString = false;
                token+=e;
                ans.push_back({token,3});
                token="";
                continue;
            }else if(e=='$'){
                canBeString = false;
                ans.push_back({token,-1});
                token="";
            }else{
                token+=e;
                continue;
            }
        }
        if(this->reserved.count(token) !=0 && token!="" && !skip){
            int code = checkToken(token);
            ans.push_back({token, code});
            token="";
        }
        if(this->reserved.count(aux) != 0){
            QString contenido = QString::fromStdString(token);
            if((e=='!' && this->entrada[i+1] == '=') || (e=='=' && this->entrada[i+1] == '=')){
                int code = checkToken(token);
                ans.push_back({token, code});
                token="";
                token+=e;
                skip=true;
                continue;
            }
            if(token == "!" && e=='='){
                int code = checkToken(token+e);
                ans.push_back({token+e, code});
                token="";
                skip=false;
                continue;
            }if(token == "=" && e=='='){
                int code = checkToken(token+e);
                ans.push_back({token+e, code});
                token="";
                skip=false;
                continue;
            }if(token == ""){
                int code = checkToken(aux);
                ans.push_back({aux, code});
                continue;
            }
            int code = checkToken(token);
            ans.push_back({token, code});
            code = checkToken(aux);
            ans.push_back({aux, code});
            token="";
            continue;
        }else if(token == canBe){
            canBeString=true;
            token+=e;
            continue;
        }else if(e==';'){
            checkToken(token);
            string aux=""; aux+=e;
            checkToken(aux);
            token="";
        }else if((e=='$' && token != "") || (isWhitespace(e) && token != "")){
            int code = checkToken(token);
            ans.push_back({token, code});
            token="";
            token+=e;
            code = checkToken(token);
            ans.push_back({token, code});
        }else if(isWhitespace(e) && token == ""){
            continue;
        }else{
            token+=e;
        }
        if(isdigit(e) || isInteger(token) || isReal(token)){
            canBeNumber = true;
        }
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
    return c >= '0' && c <= '9' && !isWhitespace(c);
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
    if(token == ""){return false;}
    for (char c : token) {
        if (!isDigit(c) || isWhitespace(c)) {
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
