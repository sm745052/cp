#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g, dist;
int n;


void floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = g[i][j];
            if(i==j)dist[i][j] = 0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}



signed main(){
    int m;
    cin>>n>>m;
    g.resize(n+1, vector<int>(n+1, INT_MAX));
    dist.resize(n+1, vector<int>(n+1));
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = c;
    }
    floyd_warshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"dist from "<<i<<" to "<< j<<" is "<<dist[i][j]<<endl;
        }
    }
    return 0;
}
