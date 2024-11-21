#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;

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

bool iscon2(string word){
    if(word[0]!='0' || word.size()<2){
        return false;
    }
    for(int i=1;i<word.size();i++){
        if(word[i]=='0' || word[i]=='1')continue;
        return false;
    }
    return true;
}

int iscon1(string word){
    if(word.size()<4)return 0;
    string prefix = word.substr(0,3);
    for(int i=3;i<word.size();i++){
        if(!isDigit(word[i]) && !isLetter(word[i])){
            return 0;
        }
    }
    if(prefix=="ch_"){
        return 1;
    }
    else if(prefix=="bn_"){
        return 2;
    }
    return 0;
}

void solve(string word){
    if(iscon1(word)==1){
        cout<<"Character Variable" nl;
    }
    else if(iscon1(word)==2){
        cout<<"Binary Variable" nl;
    }
    else if(iscon2(word)){
        cout<<"Binary Number" nl;
    }
    else{
        cout<<"Invalid input or undefined" nl;
    }
}

int main(){
    freopen("input6.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }
}


