#define nl <<"\n"
#define dnl <<"\n\n"
#define sp <<" "<<
#define spn <<" "
#define ll long long int
#define pb push_back

#include<bits/stdc++.h>
using namespace std;

map<string,string>rule;
string st,input;
char start;

void print(){
    cout<<st;
    int i;
    for(i=0;i<15-st.size();i++){
        cout<<" ";
    }
    cout<<input;
    for(i=0;i<20-input.size();i++){
        cout<<" ";
    }
}

void solve(){
    int i,j;
    cout<<"Enter input string: ";
    cin>>input;
    input.pb('$');
//    int start=0,end=input.size();end--;
//    for(i=start;i<end;i++){
//        if(input[i]=='i' && input[i+1]=='d'){
//            input.replace(i,2,"i");
//            start=0;
//            end = input.size();
//            end--;
//        }
//    }
    cout<<"Stack          Input               Action" dnl;
    while(true){
        print();
        string tmp="";
        bool reduce = false;
        for(i=st.size()-1;i>0;i--){
            tmp.pb(st[i]);
            string tmp1 = tmp;
            reverse(tmp1.begin(),tmp1.end());
            if(rule[tmp1]!=""){
                cout<<"reduce "<<rule[tmp1]<<"->"<<tmp1 dnl;
                reduce = true;
                break;
            }
        }
        if(reduce){
            int sz = st.size()-tmp.size();
            reverse(tmp.begin(),tmp.end());
            while(st.size()!=sz){
                st.pop_back();
            }
            for(i=0;i<rule[tmp].size();i++){
                st.pb(rule[tmp][i]);
            }
        }
        else{
            if(input.size()==1)break;
            cout<<"shift" dnl;
            st.pb(input[0]);
            input.erase(input.begin());
        }
    }
    input.pb(start);
    if(input==st)cout<<"aacepted!" nl;
    else cout<<"rejected!" nl;
}

int main(){
    ifstream file;
    file.open("input10.txt");
    string input;
    st="$";
    bool done = false;
    while(getline(file,input)){
        string left="",right="";
        bool arrow = false;
        for(int i=0;i<input.size();i++){
            if(input[i]=='-' && input[i+1]=='>'){
                arrow = true;
                i++;
                continue;
            }
            if(arrow){
                right.pb(input[i]);
            }
            else{
                left.pb(input[i]);
            }
        }
        rule[right]=left;
        if(!done){
            start=left[0];
            done=true;
        }
    }
    file.close();
    solve();
}

