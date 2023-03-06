#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7






void solve(int test){
    int n;
    cin>>n;
    int arr[n];
    int ps=0, ns=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0)ns+=arr[i];
        else ps+=arr[i];
    }
    cout<<max(abs(ns)-abs(ps), abs(ps)-abs(ns))<<endl;
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