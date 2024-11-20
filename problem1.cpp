#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int i,j,k;
    string s;
    vector<char>letters,digits,others;
    int words = 0;

    ifstream file;
    file.open("input1.txt");
    if(file.is_open()){
        getline(file,s);
    }
    file.close();

    for(i=0;i<s.size();i++){
        if(s[i]==' '){
            words++;
        }
        else if(s[i]>='0' && s[i]<='9'){
            digits.pb(s[i]);
        }
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            letters.pb(s[i]);
        }
        else{
            others.pb(s[i]);
        }
    }
    if(s.size()>0){
        words++;
    }
    cout<<"Given string: "<<s nl;
    cout<<endl<<"Number of words: "<<words dnl;
    cout<<"Number of letters: "<<letters.size() dnl;
    cout<<"Number of digits: "<<digits.size() dnl;
    cout<<"Number of other characters: "<<others.size() dnl;

    cout<<"The letters are: ";
    for(auto p:letters){
        cout<<p spn;
    }
    cout<<"\n\n";

    cout<<"The digits are: ";
    for(auto p:digits){
        cout<<p spn;
    }
    cout<<"\n\n";


    cout<<"The other characters are: ";
    for(auto p:others){
        cout<<p spn;
    }
    cout<<"\n\n";


}

int main(){
    solve();
}
