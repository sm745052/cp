#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7






void solve(int test){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int ans = INT_MIN;
    for(int i=1;i<n-1;i++){
        ans = max(ans, 2*arr[i+1]-arr[i]-arr[0]);
    }
    for(int i=1;i<n-1;i++){
        ans=max(ans, arr[i]+arr[n-1]-2*arr[i-1]);
    }
    cout<<ans<<endl;
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