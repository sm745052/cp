#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g;
vector<int> dist;
vector<vector<int>> edges;
int n;
int m;

void bellman_ford(int s){
    dist[s] = 0;
    for(int k=1;k<=n-1;k++){
        // iterating over edges
        for(int i=0;i<m;i++){
            if(dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]]){
                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            }
        }
    }
    
    for(int i=0;i<m;i++){
        if(dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]]){
            cout<<"negative cycle detected"<<endl;
            return;
        }
    }
}



signed main(){
    cin>>n>>m;
    g.resize(n+1, vector<int>(n+1, INT_MAX));
    dist.resize(n+1, INT_MAX);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        edges.push_back({a, b, c});
        g[a][b] = c;
    }
    int s = 4;
    bellman_ford(s);
    for(int i=1;i<=n;i++){
        cout<<"dist from "<<s<<" to "<< i<<" is "<<dist[i]<<endl;
    }
    return 0;
}
