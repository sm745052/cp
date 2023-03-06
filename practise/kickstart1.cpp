#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7

void solve(int test)
{
    int m, n, p;
    cin>>m>>n>>p;
    int ans= 0;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int j=0;j<n;j++){
        int ma = -1;
        int jh;
        for(int i=0;i<m;i++){
            if(arr[i][j]>ma)ma=arr[i][j];
            if(i==p-1)jh=arr[i][j];
        }
        ans+=ma-jh;
    }
    cout<<"Case #"<<test<<": "<<ans<<endl;
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