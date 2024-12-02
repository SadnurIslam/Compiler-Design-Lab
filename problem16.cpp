#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;


bool isop(char op){
    if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^'){
        return true;
    }
    return false;
}

int precedence(char op){
    if(op=='^')return 3;
    if(op=='/' || op=='*')return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}
void solve(){
    string infix;
    cin>>infix;
    infix.pb(')');
    string postfix="";
    stack<char>st;
    st.push('(');
    int i=0;
    while(!st.empty()){
        if(infix[i]=='('){
            st.push('(');
        }
        else if(infix[i]==')'){
            while(st.top()!='('){
                postfix.pb(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(isop(infix[i])){
            while(precedence(st.top())>=precedence(infix[i])){
                postfix.pb(st.top());
                st.pop();
            }
            st.push(infix[i]);
        }
        else{
            postfix.pb(infix[i]);
        }
        i++;
    }
    infix.pop_back();
    cout<<"Infix  : "<<infix nl;
    cout<<"Postfix: "<<postfix dnl;

}

int main(){
    solve();
}

