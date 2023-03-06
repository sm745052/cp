#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
void solve(){
    int n, k;
    cin>>n>>k;
    int h[n], p[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<pair<int, int> >g1;
    for(int i=0;i<n;i++){
        g1.push_back({p[i], h[i]});
    }
    sort(g1.begin(), g1.end());
    g1.push_back({0, 0});
    int d=0;
    for(int i=0;i<g1.size()-1;i++){
        if(d>=g1[i].second)continue;
        if(i)
            k -= g1[i].first;
        g1[i].second -= d;
        while(k>0 && g1[i].second>0){
            g1[i].second -= k;
            d += k;
            if(g1[i].second>0)
                k -= g1[i].first;
        }
        if(g1[i].second>0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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