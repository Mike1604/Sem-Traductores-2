#include "funcnodes.h"

funcNodes::funcNodes(){}
funcNodes::funcNodes(const string tipo, string parametros) : tipo(tipo), parametros(parametros) {}

void funcNodes::setParametros(string parametros){
    this->parametros=parametros;
}
void funcNodes::setTipo(string tipo){
    this->tipo=tipo;
}
string funcNodes::getParametros(){
    return this->parametros;
}
string funcNodes::getTipo(){
    return this->tipo;
}
