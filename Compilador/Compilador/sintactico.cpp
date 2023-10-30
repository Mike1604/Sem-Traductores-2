#include "sintactico.h"
#include "QtDebug"
Sintactico::Sintactico(vector<pair<string,int>> tokens)
{
    reverse(tokens.begin(), tokens.end());
    this->tokens = tokens;
    SintacticoNode aux("$",0,false);
    this->stackNodes.push_back(aux);
    this->input.push_back(tokensToString());
    this->pila.push_back(stackToString());
    this->actualState = aux.getState();
    analize();
}
void Sintactico::analize(){
    bool f=false;
    int i=this->tokens.size()-1;
    while(i>=0){
        this->actualState = this->stackNodes.back().getState();
        QString contenido = QString::fromStdString(this->tokens[i].first);
        //qDebug()<<"Nodo Actual token: "<< contenido << "Code: "<< this->tokens[i].second;
        int nextState = this->lr1[this->actualState][this->tokens[i].second];
        if(nextState==0){
            break;
        }else if(nextState<0){
            nextState = (nextState * (-1))-1;
            if(nextState==0){f=true; break;}
            string rule = "R";
            rule+=to_string(nextState);
            qDebug()<<"########  Regla Encontrada"<< QString::fromStdString(rule);
            this->setTreeNode(rule);
            //Here I remove the tokens by the rule
            for(int i=0; i<this->rules[rule].first; i++){
                this->stackNodes.pop_back();
            }
            //Here i look for the next state for the rule
            nextState = this->stackNodes.back().getState();
            nextState = this->lr1[nextState][this->reduction[this->rules[rule].second]];
            //Here I introduce the new reduction
            SintacticoNode aux(this->rules[rule].second, nextState,true);
            this->stackNodes.push_back(aux);
            this->pila.push_back(stackToString());
            this->input.push_back(tokensToString());
            this->output.push_back(this->expresiones[rule]);
            if(rule == "R0"){f=true;}
        }else{
            SintacticoNode aux(this->tokens[i].first, nextState,false);
            string out = "d";
            out+=to_string(nextState);
            this->output.push_back(out);
            stackNodes.push_back(aux);
            this->tokens.pop_back();
            this->input.push_back(tokensToString());
            this->pila.push_back(stackToString());
            i--;
        }
        qDebug()<<"Proximo Estado: "<<nextState;

    }
    if(!f){this->output.push_back("-1 Not acepted");}
    else{
        this->output.push_back("R0 Accepted");
        this->correctAnalice=true;
    }

}
string Sintactico::stackToString(){
    string aux="";
    for(auto e:this->stackNodes){
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
void Sintactico::setTreeNode(string rule){
    if(rule == "R1"){
        this->rootSintactico.setToken("<programa>");
        TreeNode nodeAux("<programa>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        rootSintactico.setIndex(auxIndex);

    }else if(rule == "R2"){
        TreeNode nodeAux("<Definiciones>");
        Tree.push_back(nodeAux);
        Tree[Tree.size()-1].setIndex(Tree.size()-1);
        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R3"){
        TreeNode nodeAux("<Definiciones>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R4"){
        TreeNode nodeAux("<Definicion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R5"){
        TreeNode nodeAux("<Definicion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R6"){
        TreeNode nodeAux("<DefVar>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idTipo("Tipo");
        Tree.push_back(idTipo);
        int idTipoIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idTipoIndex);
        Tree[idTipoIndex].setIndex(idTipoIndex);

        TreeNode textNodeTipo(stackNodes[stackNodes.size()-4].getToken());
        Tree.push_back(textNodeTipo);
        Tree[idTipoIndex+1].setIndex(idTipoIndex+1);
        Tree[idTipoIndex].setNext(idTipoIndex+1);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-3].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opCom(";");
        Tree.push_back(opCom);
        int indexopCom = Tree.size()-1;
        Tree[indexopCom].setIndex(indexopCom);
        Tree[auxIndex].setNext(indexopCom);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R7"){
        TreeNode nodeAux("<ListaVar>");
        Tree.push_back(nodeAux);
        Tree[Tree.size()-1].setIndex(Tree.size()-1);
        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R8"){
        TreeNode nodeAux("<ListaVar>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opComa(",");
        Tree.push_back(opComa);
        int indexopComa = Tree.size()-1;
        Tree[indexopComa].setIndex(indexopComa);
        Tree[auxIndex].setNext(indexopComa);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R9"){
        TreeNode nodeAux("<DefFunc>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opCierre(")");
        Tree.push_back(opCierre);
        int indexopCierre = Tree.size()-1;
        Tree[indexopCierre].setIndex(indexopCierre);
        Tree[auxIndex].setNext(indexopCierre);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opApertura("(");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-5].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);


        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R10"){
        TreeNode nodeAux("<Parametros>");
        Tree.push_back(nodeAux);
        Tree[Tree.size()-1].setIndex(Tree.size()-1);
        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R11"){
        TreeNode nodeAux("<Parametros>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idTipo("Tipo");
        Tree.push_back(idTipo);
        int idTipoIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idTipoIndex);
        Tree[idTipoIndex].setIndex(idTipoIndex);

        TreeNode textNodeTipo(stackNodes[stackNodes.size()-3].getToken());
        Tree.push_back(textNodeTipo);
        Tree[idTipoIndex+1].setIndex(idTipoIndex+1);
        Tree[idTipoIndex].setNext(idTipoIndex+1);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-1].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R12"){
        TreeNode nodeAux("<ListaParam>");
        Tree.push_back(nodeAux);
        Tree[Tree.size()-1].setIndex(Tree.size()-1);
        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R13"){
        TreeNode nodeAux("<ListaParam>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opComa(",");
        Tree.push_back(opComa);
        int indexopComa = Tree.size()-1;
        Tree[indexopComa].setIndex(indexopComa);
        Tree[auxIndex].setNext(indexopComa);

        TreeNode idTipo("Tipo");
        Tree.push_back(idTipo);
        int idTipoIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idTipoIndex);
        Tree[idTipoIndex].setIndex(idTipoIndex);

        TreeNode textNodeTipo(stackNodes[stackNodes.size()-3].getToken());
        Tree.push_back(textNodeTipo);
        Tree[idTipoIndex+1].setIndex(idTipoIndex+1);
        Tree[idTipoIndex].setNext(idTipoIndex+1);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R14"){
        TreeNode nodeAux("<BloqFunc>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opApertura("{");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opCierre("}");
        Tree.push_back(opCierre);
        int indexopCierre = Tree.size()-1;
        Tree[indexopCierre].setIndex(indexopCierre);
        Tree[auxIndex].setNext(indexopCierre);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R15"){
        TreeNode nodeAux("<DefLocales>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R16"){
        TreeNode nodeAux("<DefLocales>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R17"){
        TreeNode nodeAux("<DefLocal>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R18"){
        TreeNode nodeAux("<DefLocal>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R19"){
        TreeNode nodeAux("<Sentencias>");
        Tree.push_back(nodeAux);
        Tree[Tree.size()-1].setIndex(Tree.size()-1);
        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R20"){
        TreeNode nodeAux("<Sentencias>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R21"){
        TreeNode nodeAux("<Sentencia>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-4].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        TreeNode opEqual("=");
        Tree.push_back(opEqual);
        int indexOpEqual = Tree.size()-1;
        Tree[indexOpEqual].setIndex(indexOpEqual);
        Tree[auxIndex].setNext(indexOpEqual);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opCom(";");
        Tree.push_back(opCom);
        int indexopCom = Tree.size()-1;
        Tree[indexopCom].setIndex(indexopCom);
        Tree[auxIndex].setNext(indexopCom);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R22"){
        TreeNode nodeAux("<Sentencia>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode ifState("if");
        Tree.push_back(ifState);
        int indexifState = Tree.size()-1;
        Tree[indexifState].setIndex(indexifState);
        Tree[auxIndex].setNext(indexifState);

        TreeNode opApertura("(");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opClose(")");
        Tree.push_back(opClose);
        int indexopClose = Tree.size()-1;
        Tree[indexopClose].setIndex(indexopClose);
        Tree[auxIndex].setNext(indexopClose);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R23"){
        TreeNode nodeAux("<Sentencia>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode whileState("while");
        Tree.push_back(whileState);
        int indexwhileStatee = Tree.size()-1;
        Tree[indexwhileStatee].setIndex(indexwhileStatee);
        Tree[auxIndex].setNext(indexwhileStatee);

        TreeNode opApertura("(");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opClose(")");
        Tree.push_back(opClose);
        int indexopClose = Tree.size()-1;
        Tree[indexopClose].setIndex(indexopClose);
        Tree[auxIndex].setNext(indexopClose);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R24"){
        TreeNode nodeAux("<Sentencia>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode returnState("return");
        Tree.push_back(returnState);
        int indexreturnState = Tree.size()-1;
        Tree[indexreturnState].setIndex(indexreturnState);
        Tree[auxIndex].setNext(indexreturnState);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R25"){
        TreeNode nodeAux("<Sentencia>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R26"){
        TreeNode nodeAux("<Otro>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R27"){
        TreeNode nodeAux("<Otro>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode elseState("else");
        Tree.push_back(elseState);
        int indexelseState = Tree.size()-1;
        Tree[indexelseState].setIndex(indexelseState);
        Tree[auxIndex].setNext(indexelseState);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R28"){
        TreeNode nodeAux("<Bloque>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opApertura("{");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opCierre("}");
        Tree.push_back(opCierre);
        int indexopCierre = Tree.size()-1;
        Tree[indexopCierre].setIndex(indexopCierre);
        Tree[auxIndex].setNext(indexopCierre);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R29"){
        TreeNode nodeAux("<ValorRegresa>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R30"){
        TreeNode nodeAux("<ValorRegresa>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R31"){
        TreeNode nodeAux("<Argumentos>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R32"){
        TreeNode nodeAux("<Argumentos>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R33"){
        TreeNode nodeAux("<ListaArgumentos>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R34"){
        TreeNode nodeAux("<ListaArgumentos>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opComa(",");
        Tree.push_back(opComa);
        int indexopComa = Tree.size()-1;
        Tree[indexopComa].setIndex(indexopComa);
        Tree[auxIndex].setNext(indexopComa);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[Tree.size()-1]);
    }else if(rule == "R35"){
        TreeNode nodeAux("<Termino>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R36"){
        TreeNode nodeAux("<Termino>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(this->stackNodes.back().getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);
        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R37"){
        TreeNode nodeAux("<Termino>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("Entero");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(this->stackNodes.back().getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);
        this->rulesStack.push_back(Tree[auxIndex]);

    }else if(rule == "R38"){
        TreeNode nodeAux("<Real>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("Entero");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(this->stackNodes.back().getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);
        this->rulesStack.push_back(Tree[auxIndex]);

    }else if(rule == "R39"){
        TreeNode nodeAux("<Termino>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("Cadena");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(this->stackNodes.back().getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);
        this->rulesStack.push_back(Tree[auxIndex]);

    }else if(rule == "R40"){
        TreeNode nodeAux("<LlamadaFunc>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode idNode("identificador");
        Tree.push_back(idNode);
        int idIndex = Tree.size()-1;
        Tree[auxIndex].setNext(idIndex);
        Tree[idIndex].setIndex(idIndex);

        TreeNode textNode(stackNodes[stackNodes.size()-4].getToken());
        Tree.push_back(textNode);
        Tree[idIndex+1].setIndex(idIndex+1);
        Tree[idIndex].setNext(idIndex+1);

        TreeNode opApertura("(");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opClose(")");
        Tree.push_back(opClose);
        int indexopClose = Tree.size()-1;
        Tree[indexopClose].setIndex(indexopClose);
        Tree[auxIndex].setNext(indexopClose);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R41"){
        TreeNode nodeAux("<SentenciaBloque>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R42"){
        TreeNode nodeAux("<SentenciaBloque>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R43"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opApertura("(");
        Tree.push_back(opApertura);
        int indexopApertura = Tree.size()-1;
        Tree[indexopApertura].setIndex(indexopApertura);
        Tree[auxIndex].setNext(indexopApertura);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode opClose(")");
        Tree.push_back(opClose);
        int indexopClose = Tree.size()-1;
        Tree[indexopClose].setIndex(indexopClose);
        Tree[auxIndex].setNext(indexopClose);

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R44"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opSuma("opSuma");
        Tree.push_back(opSuma);
        int indexopSuma= Tree.size()-1;
        Tree[indexopSuma].setIndex(indexopSuma);
        Tree[auxIndex].setNext(indexopSuma);

        TreeNode opSumaText(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opSumaText);
        Tree[indexopSuma+1].setIndex(indexopSuma+1);
        Tree[indexopSuma].setNext(indexopSuma+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R45"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        TreeNode opNot("opNot");
        Tree.push_back(opNot);
        int indexopNot= Tree.size()-1;
        Tree[indexopNot].setIndex(indexopNot);
        Tree[auxIndex].setNext(indexopNot);

        TreeNode opNopText("!");
        Tree.push_back(opNopText);
        Tree[indexopNot+1].setIndex(indexopNot+1);
        Tree[indexopNot].setNext(indexopNot+1);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R46"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOpMul("OpMul");
        Tree.push_back(auxOpMul);
        int indexauxOpMul = Tree.size()-1;
        Tree[indexauxOpMul].setIndex(indexauxOpMul);

        TreeNode opMul(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opMul);
        int indexopMul = Tree.size()-1;
        Tree[indexopMul].setIndex(indexopMul);

        Tree[indexauxOpMul].setNext(indexopMul);
        Tree[auxIndex].setNext(indexauxOpMul);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R47"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOp("OpSuma");
        Tree.push_back(auxOp);
        int indexOp = Tree.size()-1;
        Tree[indexOp].setIndex(indexOp);

        TreeNode opSuma(stackNodes[stackNodes.size()-3].getToken());
        Tree.push_back(opSuma);
        int indexOpSuma = Tree.size()-1;
        Tree[indexOpSuma].setIndex(indexOpSuma);

        Tree[indexOp].setNext(indexOpSuma);
        Tree[auxIndex].setNext(indexOp);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R48"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOpMul("opRelac");
        Tree.push_back(auxOpMul);
        int indexauxOpMul = Tree.size()-1;
        Tree[indexauxOpMul].setIndex(indexauxOpMul);

        TreeNode opMul(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opMul);
        int indexopMul = Tree.size()-1;
        Tree[indexopMul].setIndex(indexopMul);

        Tree[indexauxOpMul].setNext(indexopMul);
        Tree[auxIndex].setNext(indexauxOpMul);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R49"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOpMul("opIgualdad");
        Tree.push_back(auxOpMul);
        int indexauxOpMul = Tree.size()-1;
        Tree[indexauxOpMul].setIndex(indexauxOpMul);

        TreeNode opMul(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opMul);
        int indexopMul = Tree.size()-1;
        Tree[indexopMul].setIndex(indexopMul);

        Tree[indexauxOpMul].setNext(indexopMul);
        Tree[auxIndex].setNext(indexauxOpMul);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R50"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOpMul("opAnd");
        Tree.push_back(auxOpMul);
        int indexauxOpMul = Tree.size()-1;
        Tree[indexauxOpMul].setIndex(indexauxOpMul);

        TreeNode opMul(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opMul);
        int indexopMul = Tree.size()-1;
        Tree[indexopMul].setIndex(indexopMul);

        Tree[indexauxOpMul].setNext(indexopMul);
        Tree[auxIndex].setNext(indexauxOpMul);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R50"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        TreeNode auxOpMul("opOr");
        Tree.push_back(auxOpMul);
        int indexauxOpMul = Tree.size()-1;
        Tree[indexauxOpMul].setIndex(indexauxOpMul);

        TreeNode opMul(stackNodes[stackNodes.size()-2].getToken());
        Tree.push_back(opMul);
        int indexopMul = Tree.size()-1;
        Tree[indexopMul].setIndex(indexopMul);

        Tree[indexauxOpMul].setNext(indexopMul);
        Tree[auxIndex].setNext(indexauxOpMul);

        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();

        this->rulesStack.push_back(Tree[auxIndex]);
    }else if(rule == "R52"){
        TreeNode nodeAux("<Expresion>");
        Tree.push_back(nodeAux);
        int auxIndex = Tree.size()-1;
        Tree[auxIndex].setIndex(auxIndex);
        Tree[auxIndex].setNext(rulesStack.back().getIndex());
        rulesStack.pop_back();
        this->rulesStack.push_back(Tree[auxIndex]);
    }
    qDebug()<< "Tokens Stack:";
    for(auto e:rulesStack){
        qDebug() << QString::fromStdString(e.getToken());
    }
}

vector<TreeNode> Sintactico::getTree(){
    return this->Tree;
}

string Sintactico::getTreeToString(){
    if(!correctAnalice){return "Error";}
    string ans;
    int start = rootSintactico.getIndex();
    stack<pair<int,int>> dfs;
    dfs.push({start,0});
    while(!dfs.empty()){
        pair<int,int> aux = dfs.top();
        dfs.pop();
        for(int i =0; i<aux.second; i++){
            ans+="\t";
        }
        ans+=to_string(aux.second);
        ans+=" ";
        ans+=Tree[aux.first].getToken();
        ans+="\n";
        for(auto e:Tree[aux.first].getNexts()){
            dfs.push({e,aux.second+1});
        }
    }
    return ans;
}
