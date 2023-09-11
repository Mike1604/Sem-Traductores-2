#include "sintactico.h"
#include "QtDebug"
Sintactico::Sintactico(vector<pair<string,int>> tokens)
{
    reverse(tokens.begin(), tokens.end());
    this->tokens = tokens;
    SintacticoNode aux("$",0);
    this->stack.push_back(aux);
    this->input.push_back(tokensToString());
    this->pila.push_back(stackToString());
    this->actualState = aux.getState();
    analize();
}
void Sintactico::analize(){
    bool f=false;
    int i=this->tokens.size()-1;
    while(i>=0){
        this->actualState = this->stack.back().getState();
        QString contenido = QString::fromStdString(this->tokens[i].first);
       qDebug()<<"Nodo Actual token: "<< contenido << "Code: "<< this->tokens[i].second;
        int nextState = this->lr1[this->actualState][this->tokens[i].second];
        if(nextState==0){
            break;
        }else if(nextState<0){
            nextState = (nextState * (-1))-1;
            if(nextState==0){f=true; break;}
            string rule = "R";
            rule+=to_string(nextState);
            //Here I remove the tokens by the rule
            for(int i=0; i<this->rules[rule].first; i++){
                this->stack.pop_back();
            }
            //Here i look for the next state for the rule
            nextState = this->stack.back().getState();
            nextState = this->lr1[nextState][this->reduction[this->rules[rule].second]];
            //Here I introduce the new reduction
            SintacticoNode aux(this->rules[rule].second, nextState);
            this->stack.push_back(aux);
            this->pila.push_back(stackToString());
            this->input.push_back(tokensToString());
            this->output.push_back(this->expresiones[rule]);
            if(rule == "R0"){f=true;}
        }else{
            SintacticoNode aux(this->tokens[i].first, nextState);
            string out = "d";
            out+=to_string(nextState);
            this->output.push_back(out);
            stack.push_back(aux);
            this->tokens.pop_back();
            this->input.push_back(tokensToString());
            this->pila.push_back(stackToString());
            i--;
        }
        qDebug()<<"Proximo Estado: "<<nextState;

    }
    if(!f){this->output.push_back("-1 Not acepted");;}
    else{
        this->output.push_back("R0 Accepted");
    }

}
string Sintactico::stackToString(){
    string aux="";
    for(auto e:this->stack){
        aux+=e.toString();
    }
    return aux;
}
string Sintactico::tokensToString(){
    vector<pair<string, int>> tokensC(this->tokens.rbegin(), this->tokens.rend());
    string aux="";
    for(auto e:tokensC){
        aux+=e.first;
    }
    return aux;
}
vector<string> Sintactico::getOutput(){
    return this->output;
}
vector<string> Sintactico::getInput(){
    return this->input;
}
vector<string> Sintactico::getPila(){
    return this->pila;
}
