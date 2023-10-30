#include "sintacticonode.h"

SintacticoNode::SintacticoNode(string token, int state, bool isRule)
{
    this->token = token;
    this->state = state;
    this->isRule = isRule;
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
