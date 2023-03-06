#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long




void solve()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    stack<char> g1;
    g1.push('0'-1);
    for(int i=0;i<s.length();i++){
        if(g1.size()==1 &&s[i]=='0'){
            k--;continue;
        }
        while(!(s[i]=='0' && g1.size()==2) && g1.top()>s[i] && k>0){
            g1.pop();
            k--;
        }
        g1.push(s[i]);
    }
    while(k>0){
        g1.pop();
        k--;
    }
    string str="";
    while(g1.top()!='0'-1){
        str = g1.top()+str;
        g1.pop();
    }
    cout<<str<<endl;
}



int32_t main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}