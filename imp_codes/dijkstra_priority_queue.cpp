#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pb push_back
using namespace std;
using ii = pair<int, int>;
vector<vector<ii>> g;
vector<int>vis, d;
int n;

void dijkstra(int sc){
    vis.assign(n+1, 0);
    d.assign(n+1, 1e18);
    d[sc] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({d[sc], sc});
    while(!pq.empty()){
        int nd = pq.top().S;
        int d_nd = pq.top().F;
        // cout<<nd<<" popped with d = "<<d_nd<<"and d[nd] = "<<d[nd]<<"\n";
        pq.pop();
        if(d_nd!=d[nd])continue;
        for(auto i:g[nd]){
            if(d[i.F]>d[nd] + i.S){
                d[i.F] = d[nd] + i.S;
                pq.push({d[i.F], i.F});
            }
        }
    }
}






signed main(){
    n=5;
    g.resize(n+1);
    vector<pair<int, ii>> ed = {{1, {2, 3}},{2, {3, 5}},{4, {2, 5}}, {20, {2, 1}}};
    for(auto i:ed){
        g[i.S.F].pb({i.S.S,i.F});
        g[i.S.S].pb({i.S.F,i.F});
    }
    dijkstra(2);
    for(int i=1;i<=n;i++){
        cout<<i<<"--->"<<d[i]<<"\n";
    }
    return 0;
}
