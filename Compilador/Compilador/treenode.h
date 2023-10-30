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
public:
    TreeNode();
    TreeNode(const string& token, int nextNode, int index);
    TreeNode(const string& token);
    void setToken(string token);
    void setNext(int next);
    void setIndex(int index);
    string getToken();
    vector<int> getNexts();
    int getIndex();
};

#endif // TREENODE_H
