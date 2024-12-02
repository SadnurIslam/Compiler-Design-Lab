#include<bits/stdc++.h>
using namespace std;
int top,mxstk;
double STACK[1000];
class my_stack{
public:
    void push(char item){
        top = top +1;
        STACK[top]=item;
    }

    void pop(){
        top= top -1;
    }
    double topp(){
        return STACK[top];
    }

    bool empty(){
        if(top==0){
            return true;
        }
        return false;
    }
};

bool isOperand(char s){
    if(s>='A' && s<='Z')
        return true;
    return false;
}

bool check(char pr, char ex){
    if(ex=='^'){
        return true;
    }
    if(ex=='/' || ex=='*'){
        if(pr=='^')
            return false;
        return true;
    }
    if(ex=='+' || ex=='-'){
        if(pr=='+' || pr=='-'){
            return true;
        }
        return false;
    }
    return false;
}

bool isOperator(char s){
    if(s=='+'){
        return true;
    }
    if(s=='^'){
        return true;
    }
    if(s=='-'){
        return true;
    }
    if(s=='/'){
        return true;
    }
    if(s=='*'){
        return true;
    }
    return false;
}

double operation(char s, double b, double a){
    if(s=='+'){
        return a+b;
    }
    if(s=='^'){
        return pow(a,b);
    }
    if(s=='-'){
        return a-b;
    }
    if(s=='/' && b!=0){
        return a/b;
    }
    if(s=='*'){
        return a*b;
    }
    return INT_MIN;
}

int main(){
    my_stack st; //creating object
    string s,p="";
    cin>>s;
    s.push_back(')');
    st.push('(');
    for(int i=0;i<s.size();i++){
        if(isOperand(s[i])){
            p.push_back(s[i]);
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(isOperator(s[i])){
            while(!st.empty()){
                char c = st.topp();
                if(check(s[i],c)){
                    st.pop();
                    p.push_back(c);
                }
                else break;
            }
            st.push(s[i]);
        }
        else{
            while(!st.empty()){
                char c = st.topp();
                st.pop();
                if(c=='(')break;
                p.push_back(c);
            }
        }
    }
    cout<<p <<endl;
}


