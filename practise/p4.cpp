#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7






void solve(int test){
    int n, q;
    cin>>n>>q;
    int arr[n];
    int preX[n]={0};
    int preS[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i){
            preX[i] = preX[i-1]^arr[i];
        }
        if(i){
            preS[i] = preS[i-1]+arr[i];
        }
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        int x = preX[r] ^ preX[l-1];
        if(x==0)cout<<((preS[r] - preS[l-1])?0:1)<<endl;
        else if((l-r)%2==0){
            cout<<2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}




signed main() {


#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}