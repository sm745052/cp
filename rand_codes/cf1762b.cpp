#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long




void solve(){
    int n;
    cin>>n;
    vector<pair<int, int>>g1, out;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        g1.push_back({k, i+1});
    }
    sort(g1.begin(), g1.end());
    int p_m=g1[0].first;
    for(int i=1;i<n;i++){
        if(g1[i].first%p_m!=0){
            out.push_back({g1[i].second, (1+g1[i].first/p_m)*p_m-g1[i].first});
            p_m = (1+g1[i].first/p_m)*p_m;
        }
        else{
            p_m = g1[i].first;
        }
    }
    cout<<out.size()<<endl;
    for(auto &i:out){
        cout<<i.first<<" "<<i.second<<endl;
    }
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