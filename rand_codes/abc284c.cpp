#include<bits/stdc++.h>

using namespace std;
#define int long long

void dfs(vector<vector<int> > &g, int v, vector<int> &clc){
    clc[v] = 1;
    for(auto i:g[v]){
        if(clc[i]==0)
            // clc[i] = 1;
            dfs(g,i,clc);
    }
}


signed main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> >g(n+1);
    vector<int> vis(n+1, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cl = 0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){            
            dfs(g, i, vis);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}