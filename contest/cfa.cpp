#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    string rs = "FBFFBFFB";
    rs = rs+rs+rs;
    // cout<<rs<<endl;
    for(int i=0;i<=rs.length()-k;i++){
        // cout<<rs.substr(i, k)<<endl;
        if(s==rs.substr(i, k)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
