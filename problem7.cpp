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
    set<string>keywords={"for","while","if","else","goto","void","do","int","char","public","class","exit","return","break","continue"};
    set<string>operators={"=","==","+=","-=","-","*","%","/","&","&&","|","||","!=","^","!"};
    if(keywords.find(word)!=keywords.end()){
        cout<<"Keyword" nl;
    }
    else if(operators.find(word)!=operators.end()){
        cout<<"Operator" nl;
    }
    else{
        if(word[0]=='_' || isLetter(word[0])){
            for(int i=1;i<word.size();i++){
                if(!isDigit(word[i]) && !isLetter(word[i]) && word[i]!='_'){
                    cout<<"Unknown" nl;
                    return;
                }
            }
            cout<<"Identifier" nl;
        }
        else{
            int ind = -1,c=0;
            for(int i=0;i<word.size();i++){
                if(word[i]=='.'){
                    c++;
                    ind=i;
                    continue;
                }
                if(!isDigit(word[i])){
                    c=2;
                }
                if(c>=2)break;
            }
            if(c==0){
                cout<<"Constant" nl;
            }
            else if(c==1){
                if(ind==0 || ind==(word.size()-1)){
                    cout<<"Unknown" nl;
                }
                else{
                    cout<<"Constant" nl;
                }
            }
            else{
                cout<<"Unknown" nl;
            }
        }
    }
}

int main(){
    freopen("input7.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }
}



