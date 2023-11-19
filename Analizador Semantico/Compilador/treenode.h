#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
private:
    string token;
    vector<int> next;
    int index;
    string rule;
    int hijos;
public:
    TreeNode();
    TreeNode(const string& token, int nextNode, int index);
    TreeNode(const string& token);
    void setToken(string token);
    void setNext(int next);
    void setIndex(int index);
    void setRule(string rule);
    string getRule();
    string getToken();
    vector<int> getNexts();
    int getIndex();
    int getHijos();
};

#endif // TREENODE_H
