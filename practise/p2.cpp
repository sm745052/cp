#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7






void solve(int test){
    int n;
    cin>>n;
    cout<<(n+1)/2<<endl;
    for(int i=0;i<(n+1)/2;i++){
    	int k = i*3;
    	cout<<k+1<<" "<<3*n-k<<endl;
    }
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