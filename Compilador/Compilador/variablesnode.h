#ifndef VARIABLESNODE_H
#define VARIABLESNODE_H
#include <iostream>

using namespace std;

class variablesNode
{
private:
    string tipo;
    string ambito;
    string contenido;
public:
    variablesNode();
    variablesNode(string tipo, string ambito, string contenido);
    void setTipo(string tipo);
    void setAmbito(string ambito);
    void setContenido(string contenido);
    string getTipo();
    string getAmbito();
    string getContendo();
};

#endif // VARIABLESNODE_H
