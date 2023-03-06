#include <bits/stdc++.h>
using namespace std;
#define int long long

bool esame(string s1, string s2){
    map<int, int> mp1, mp2;
    if(s1.length()!=s2.length())return 0;
    for(int i=0;i<s1.length();i++){
        mp1[s1[i]]++, mp2[s2[i]]++;
    }
    for(int i='a';i<='z';i++){
        if(mp1[i]!=mp2[i])return 0;
    }
    return 1;
}



void solve()
{
    int n, k;
    cin>>n>>k;
    string s, t;
    cin>>s>>t;
    if(n<=k){
        if(s==t)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else if(n-k-1>=k){
        if(esame(s, t)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        if(s.substr(n-k, max((int) 0, k-1-(n-k)+1)) == t.substr(n-k, max((int) 0, k-1-(n-k)+1)) && esame(s.substr(0, n-k-1-0+1)+s.substr(k, n-1-k+1), t.substr(0, n-k-1-0+1)+t.substr(k, n-1-k+1))){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
