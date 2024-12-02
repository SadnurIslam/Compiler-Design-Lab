
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
string post(string infix){
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
    return postfix;

}

void print(const vector<char>&tree, int size) {
    int i, j, space, lineGap, level = log2(size+1);
	for(i=0; i<=level; i++){
		for(j=0; j<(1<<i); j++){
			space = 2*(1<<(level-i));
			while(space--){
				cout<<" ";
			}
			cout<<tree[(1<<i)+j-1];
			space = 2*(1<<(level-i))-1;
			while(space--){
				cout<<" ";
			}
		}
		for(lineGap=0; lineGap<(level-i); lineGap++){
			cout<<"\n";
		}
	}
	cout<<endl;
}

int main(){
    string infix;
    cin>>infix;
    string s = post(infix);
    vector<char>v(10000,' ');
    stack<pair<char,int>>st;
    stack<int>ind;
    v[0] = s[s.size()-1];
    st.push({v[0],0});
    ind.push(0);
    for(int i=s.size()-2;i>=0;i--){
        if(isop(s[i])){
            int cur;
            if(st.top().second==0){
                cur=2*ind.top()+2;
                v[cur] = s[i];
                pair<char,int>p = st.top();
                st.pop();
                st.push({p.first,1});
            }
            else{
                cur=2*ind.top()+1;
                v[cur] = s[i];
                st.pop();
                ind.pop();
            }
            st.push({s[i],0});
            ind.push(cur);
        }
        else{
            int cur;
            if(st.top().second==0){
                cur=2*ind.top()+2;
                v[cur] = s[i];
                pair<char,int>p = st.top();
                st.pop();
                st.push({p.first,1});
            }
            else{
                cur=2*ind.top()+1;
                v[cur] = s[i];
                st.pop();
                ind.pop();
            }
        }
    }
    int level=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]!=' ')level=max(level,i+1);
    }
    level = log2(level);
    level++;
    level = (1<<level);
    print(v,level-2);
}

