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

bool isFloat(char ch){
    if(ch>='a' && ch<='h')
        return true;
    if(ch>='A' && ch<='H')
        return true;
    if(ch>='o' && ch<='z')
        return true;
    if(ch>='O' && ch<='Z')
        return true;
    return false;
}

void solve(string word){
    if(isFloat(word[0])){
        for(int i=1;i<word.size();i++){
            if(isDigit(word[i]) || isLetter(word[i])){
                continue;
            }
            else{
                cout<<"Invalid input or undefined" dnl;
                return;
            }
        }
        cout<<"Float variable" dnl;
    }
    else if(isDigit(word[0]) && word.size()>=3){
        if(word[0]=='0'){
            if(word[1]=='.'){
                for(int i=2;i<word.size();i++){
                    if(!isDigit(word[i])){
                        cout<<"Invalid input or undefined" dnl;
                        return;
                    }
                }
                if(word.size()==4){
                    cout<<"Float Number" dnl;
                }
                else if(word.size()>4){
                    cout<<"Double Number" dnl;
                }
                else{
                    cout<<"Invalid input or undefined" dnl;
                }
            }
            else{
                cout<<"Invalid input or undefined" dnl;
            }
        }
        else{
            int ind = -1,cnt=0;
            for(int i=0;i<word.size();i++){
                if(word[i]=='.' && ind==-1){
                    ind=i;
                    continue;
                }
                if(!isDigit(word[i])){
                    cout<<"Invalid input or undefined" dnl;
                    return;
                }
                else{
                    if(ind!=-1){
                        cnt++;
                    }
                }
            }
            if(ind==-1 || cnt<2){
                cout<<"Invalid input or undefined" dnl;
            }
            else if(cnt==2){
                cout<<"Float Number" dnl;
            }
            else{
                cout<<"Double Number" dnl;
            }
        }
    }
    else{
        cout<<"Invalid input or undefined" dnl;
    }
}

int main(){
    freopen("input5.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }
}

