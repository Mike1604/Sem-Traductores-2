#ifndef SINTACTICONODE_H
#define SINTACTICONODE_H
#include <iostream>
using namespace std;
class SintacticoNode
{
private:
    string token;
    int state;
public:
    SintacticoNode(string token, int state);
    string toString();
    string getToken();
    int getState();
};

#endif // SINTACTICONODE_H
