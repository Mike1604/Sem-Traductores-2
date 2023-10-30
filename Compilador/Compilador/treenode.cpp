#include "treenode.h"
TreeNode::TreeNode(){
    this->token = "";
    this->index=-1;
}

TreeNode::TreeNode(const string& token, int nextNode, int index) : token(token), next(nextNode), index(index) {}

TreeNode::TreeNode(const string& token) : token(token){}

void TreeNode::setToken(string token){
    this->token = token;
}

void TreeNode::setNext(int next){
    this->next.push_back(next);
}

void TreeNode::setIndex(int index){
    this->index=index;
}

int TreeNode::getIndex(){
    return  this->index;
}

string TreeNode::getToken(){
    return this->token;
}

vector<int> TreeNode::getNexts(){
    return this->next;
}


