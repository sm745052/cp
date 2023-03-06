#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

void solve()
{
    int n;
    cin>>n;
    map<int, int>g1;
    int mi=INT_MAX, ma=INT_MIN;
    int arr[n];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr[i] = k;
        g1[k]++;
        mi = min(mi, k);
        ma = max(ma, k);
    }
    int k = abs(mi-ma);
    int ctr=0;
    // cout<<k<<endl;
    for(int i=0;i<n;i++){
        if(k==0 && g1[arr[i]]>=2){
            ctr+=g1[arr[i]]-1;
        }
        else{
            if(g1[arr[i]+k])ctr+=g1[arr[i]+k];
            if(g1[arr[i]-k])ctr+=g1[arr[i]-k];
        }
    }
    cout<<ctr<<endl;
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