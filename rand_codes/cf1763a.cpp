#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int bits[32][n];
    int ma[32], mi[32];
    for(int i=0;i<32;i++){
        ma[i] = LLONG_MIN;
        mi[i] = LLONG_MAX;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=31;j>=0;j--){
            bits[j][i] = 1 & arr[i]>>j;
            ma[j] = max(ma[j], bits[j][i]);
            mi[j] = min(mi[j], bits[j][i]);
        }
    }
    for(int j=31;j>=0;j--){
        // cout<<(ma[j]-mi[j])<<endl;
        ans += (1<<j)*(ma[j]-mi[j]);
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