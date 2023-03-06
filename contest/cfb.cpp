#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s1, s2;
    cin>>s1>>s2;
    if(s1[0]==s2[0]){
        cout<<"YES"<<endl;
        cout<<s1[0]<<"*"<<endl;
    }
    else if(s1[s1.length()-1]==s2[s2.length()-1]){
        cout<<"YES"<<endl;
        cout<<"*"<<s1[s1.length()-1]<<endl;
    }
    else{
        for(int i=0;i<s1.length()-2+1;i++){
            for(int j=0;j<s2.length()-2+1;j++){
                if(s1.substr(i, 2)==s2.substr(j, 2)){
                    cout<<"YES"<<endl;
                    cout<<"*"<<s1.substr(i, 2)<<"*"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
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
