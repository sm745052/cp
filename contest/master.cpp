#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define F first
#define S second
int n, m;
vector<vector<ii> > g;
vector<int> dist;
vector<int> vis;

class prioritizer{
public: bool operator()(ii a, ii b){
        return a.S<b.second;
    }
};




void dijkstra(int sc){
    priority_queue<ii, vector<ii>, prioritizer> pq;
    dist[sc] = 0;
    pq.push({sc, 0});
    while(!pq.empty()){
        auto mn = pq.top();
        pq.pop();
        if(vis[mn.F])continue;
        vis[mn.F]=1;
        for(auto i:g[mn.F]){
            int neigh = i.F;
            int wt = i.S;
            if(dist[neigh] >= dist[mn.F]+wt){
                dist[neigh] = dist[mn.F] + wt;
                pq.push({neigh, dist[neigh]});
            }
        }
    }
}


signed main(){
    cin>>n>>m;
    g.resize(n+1), dist.resize(n+1, 1e18), vis.resize(n+1, 0);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c}), g[b].push_back({a, c});
    }
    int s;
    cin>>s;
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<i<<"---"<<dist[i]<<endl;
    }
}