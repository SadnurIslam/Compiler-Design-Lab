#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;


void solve(string words){
    set<string>pn={"Sagor","Selim","Salma","Nipu"};
    set<string>p={"he","she","I","we","you","they"};
    set<string>v={"read","eat","take","run","write"};
    set<string>n={"book","cow","dog","home","grass","rice","mango"};
    vector<string>word;
    string tmp = "";
    words.pb(' ');
    for(int i=0;i<words.size();i++){
        if(words[i]==' '){
            word.pb(tmp);
            tmp="";
        }
        else
            tmp.pb(words[i]);
    }

    if(word.size()>3 || word.size()<2){
        cout<<"Invalid" nl;
        return;
    }
    bool isvalid = false;
    if(pn.find(word[0])!=pn.end() || p.find(word[0])!=p.end()){
        if(v.find(word[1])!=v.end()){
            if(word.size()==3){
                if(n.find(word[2])!=n.end()){
                    isvalid = true;
                }
            }
            else{
                isvalid = true;
            }
        }
    }
    if(isvalid)cout<<"Valid" nl;
    else cout<<"Invalid" nl;
}

int main(){
    freopen("input9.txt","r",stdin);
    string input;
    while(getline(cin,input)){
        cout<<"Input: "<<input<<endl<<"Output: ";
        solve(input);
    }
}
