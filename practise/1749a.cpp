#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7

void solve(int test)
{
    int m, n;
    cin>>n>>m;
    int r[n] = {0}, c[n] = {0};
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        r[x-1]++;
        c[y-1]++;
    }
    // for(int i=0;i<n;i++)cout<<"r"<<i<<"="<<r[i]<<" c"<<i<<"="<<c[i]<<endl;
    for(int i=0;i<n;i++){
        if(!r[i]){
            cout<<"OH!YESSSSSSS"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(!c[i]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}




signed main() {


#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}