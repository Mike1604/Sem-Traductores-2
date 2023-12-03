#ifndef FUNCNODES_H
#define FUNCNODES_H
#include <iostream>

using namespace std;

class funcNodes
{
private:
    string tipo;
    string parametros;
public:
    funcNodes();
    funcNodes(string tipo, string parametros);
    void setTipo(string tipo);
    void setParametros(string parametros);
    string getTipo();
    string getParametros();
};

#endif // FUNCNODES_H
