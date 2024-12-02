#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;


bool isop(char op){
    if(op=='+' || op=='-' || op=='*' || op=='/')return true;
    return false;
}

bool isoperator(string op){
    if(op=="+" || op=="-" || op=="*" || op=="/")return true;
    return false;
}

bool isDigit(char ch){
    if(ch>='0' && ch<='9')
         return true;
    return false;
}

bool isLetter(char ch){
    if(ch>='a' && ch<='z')
        return true;
    if(ch>='A' && ch<='Z')
        return true;
    return false;
}

bool isInteger(string s){
    for(int i=0;i<s.size();i++){
        if(!isDigit(s[i]))return false;
    }
    return true;
}

bool isIdentifier(string s){
    if(isInteger(s)) return true;
    if(!isLetter(s[0]) && s[0]!='_'){
        return false;
    }
    for(int i=1;i<s.size();i++){
        if(isDigit(s[i]) || isLetter(s[i]) || s[i]=='_')continue;
        return false;
    }
    return true;
}

void solve(string word){
    vector<string>tokens;
    string tmp = "";
    bool start = false;
    bool str = false;
    for(int i=0;i<word.size();i++){
        if(word[i]!=' '){
            start=true;
        }
        if(!start)continue;
        if(word[i]==' ' && word[i-1]==' '){
            continue;
        }
        if(word[i]==' '){
            tokens.pb(tmp);
            tmp="";
        }
        else if(isop(word[i])){
            if(str){
                tokens.pb(tmp);
                tmp="";
            }
            string s = "";
            s.pb(word[i]);
            tokens.pb(s);
            str=false;
        }
        else{
            str=true;
            tmp.pb(word[i]);
        }
    }
    if(str)tokens.pb(tmp);
    if(isoperator(tokens[0]) || isoperator(tokens[tokens.size()-1])){
        cout<<"Invalid" dnl;
        return;
    }
    for(int i=0;i<tokens.size();i++){
        if(!isIdentifier(tokens[i]) && !isoperator(tokens[i])){
            cout<<"Invalid" dnl;
            return;
        }
        if(i==0)continue;
        if((isoperator(tokens[i]) && isoperator(tokens[i-1])) || (isIdentifier(tokens[i]) && isIdentifier(tokens[i-1]))){
            cout<<"Invalid" dnl;
            return;
        }
    }
    cout<<"Valid"<<endl<<endl;
}

int main(){
    freopen("input12.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }

}


