#include "sintacticonode.h"

SintacticoNode::SintacticoNode(string token, int state)
{
    this->token = token;
    this->state = state;
}
string SintacticoNode::toString(){
    string ans = "";
    ans+=this->token;
    ans+= to_string(this->state);
    return ans;
}
string SintacticoNode::getToken(){
    return this->token;
}
int SintacticoNode::getState(){
    return this->state;
}
