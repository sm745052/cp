#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7






void solve(int test){
    int n;
    cin>>n;
    int arr[n];
    int k, m = INT_MAX;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
        if(i!=0)
            m = min(m, arr[i]);
    }
    k = arr[0];
    if(k<=m)cout<<"BOB\n";
    else cout<<"ALICE\n";
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