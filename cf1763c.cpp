#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
void solve(){
    int n, k;
    cin>>n;
    int arr[n];
    int m=-1, mi=-1;
    vector<int>vmi;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>m)m=arr[i], mi=i;
    }
    int ans=0;
    ans = m*n;
    if(n==3){
        ans = max(arr[0]+arr[1]+arr[2], max(3*arr[0], max(3*arr[2], max(3*abs(arr[0]-arr[1]), 3*abs(arr[1]-arr[2])))));
    }
    if(n==2){
        ans = max(arr[0]+arr[1], 2*abs(arr[0]-arr[1]));
    }
    cout<<ans<<endl;
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