#include "variablesnode.h"

variablesNode::variablesNode(){}

variablesNode::variablesNode(const string tipo, string ambito, string contenido) : tipo(tipo), ambito(ambito), contenido(contenido) {}

void variablesNode::setAmbito(string ambito){
    this->ambito = ambito;
}

void variablesNode::setContenido(string contenido){
    this->contenido =  contenido;
}
void variablesNode::setTipo(string tipo){
    this->tipo = tipo;
}
string variablesNode::getAmbito(){
    return this->ambito;
}
string variablesNode::getContendo(){
    return this->ambito;
}
string variablesNode::getTipo(){
    return this->tipo;
}
