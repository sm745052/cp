#include<bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin>>s;
    stack<char> g;
    g.push(0);
    for(auto i:s){
        if(i!='(' && i!=')')continue;
        if(i==')'){
            if(g.top()=='('){
                g.pop();
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }
        }
        else{
            g.push('(');
        }
    }
    if(g.size()!=1){
        cout<<"No"<<endl;
    }
    cout<<"Yes"<<endl;
    return 0;
}