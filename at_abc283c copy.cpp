#include<bits/stdc++.h>

using namespace std;
#define int long long

void dfs(vector<vector<int> > &g, int v, int cl, vector<int> &clc){
    clc[v] = cl;
    for(auto i:g[v]){
        if(clc[i]==0)
            clc[i] = cl;
    }
}


signed main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> >g;
    vector<int> clc(n, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cl = 0;
    for(int i=0;i<n;i++){
        if(clc[i]==0){
            cl++;
            dfs(g, i, cl, clc);
        }
    }
    cout<<cl<<endl;
    return 0;
}