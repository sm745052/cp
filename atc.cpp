#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  stack<char>g;
  int flag=0;
  for(auto i:s){
    if(flag==0 && i=='\"')flag=1;
    else{
      if(flag==1 && i=='\"')flag=0;
    }
    if(i==','){
      if(flag)g.push(',');
      else g.push('.');
    }
    else{
      g.push(i);
    }
  }
//   cout<<g.size();
  string st="";
  while(!g.empty()){
    st.push_back(g.top());
    g.pop();
  }
  reverse(st.begin(), st.end());
  cout<<st<<endl;
  return 0;
}