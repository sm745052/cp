#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int GCD(int a, int b){
    if(b==0)return a;
    return GCD(b, a%b);
}



int LCM(int a, int b){
    return b*(a/GCD(a, b));
}



void solve()
{
    int n;
    cin>>n;
    int arr[n];
    int prd = 1;
    int lcm = 1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prd *= arr[i];
        lcm = LCM(lcm, arr[i]);
    }
    if(lcm==prd)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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