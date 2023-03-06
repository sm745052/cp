#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define F first
#define S second


int n, m;
vector<vector<ii> > g(n+1);


class prioritize{
public: bool operator ()(ii &p1, ii &p2){
        return p1.S>p2.S;
    }
};


vector<int> dist, vis;



void dijkstra(int sc){
    dist[sc] = 0;
    priority_queue<ii, vector<ii>, prioritize> pq;
    pq.push({sc, 0});
    cout<<"hello"<<endl;
    while(!pq.empty()){
        ii fs = pq.top();pq.pop();
        if(vis[fs.F])continue;
        vis[fs.F]=1;
        for(auto v:g[fs.F]){
            int neigh = v.F;
            int wt = v.S;
            if(dist[neigh]>dist[fs.F]+wt){
                dist[neigh] = dist[fs.F]+wt;
                pq.push({neigh, dist[neigh]});
            }
        }
    }
}   




void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    dist.resize(n+1, 1e18);



    for(int i=0;i<m;i++){
        int a, b, w;
        cin>>a>>b>>w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int s;
    cin>>s;
    dijkstra(s);



    for(int i=1;i<=n;i++)cout<<i<<"---> "<<dist[i]<<endl;
}

signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
