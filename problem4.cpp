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

void solve(string word){
    if((word[0]>='i' && word[0]<='n') || (word[0]>='I' && word[0]<='N')){
        for(int i=1;i<word.size();i++){
            if(isDigit(word[i]) || isLetter(word[i])){
                continue;
            }
            else{
                cout<<"Invalid input or undefined" nl;
                return;
            }
        }
        cout<<"Integer variable" nl;
    }
    else if(word[0]!='0' && isDigit(word[0])){
        for(int i=1;i<word.size();i++){
            if(!isDigit(word[i])){
                cout<<"Invalid input or undefined" nl;
                return;
            }
        }
        if(word.size()<=4){
            cout<<"ShortInt Number" nl;
        }
        else{
            cout<<"LongInt Number" nl;
        }
    }
    else{
        cout<<"Invalid input or undefined" nl;
    }
    cout<<endl;
}

int main(){
    freopen("input4.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }
}
