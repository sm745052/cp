#include<bits/stdc++.h>
using namespace std;

// dfs(root, root) is important. it sets all range excedding to root itself



vector<vector<int>> g;
vector<vector<int>> up;
vector<int> t_in, t_out;
int n, l, timer;



void dfs(int id, int pa){
    t_in[id] = ++timer;
    up[id][0]= pa;
    for(int i=1;i<=l;i++){
        up[id][i] = up[up[id][i-1]][i-1];
    }
    for(auto i:g[id]){
        if(i==pa)continue;
        dfs(i, id);
    }
    t_out[id] = ++timer;
}

int is_ancestor(int u, int v){
    if(t_in[u]<=t_in[v] && t_out[u]>=t_out[v])return 1;
    return 0;
}

int lca(int u, int v){
    if(is_ancestor(u, v)){
        return u;
    }
    if(is_ancestor(v, u)){
        return v;
    }
    for(int i=l;i>=0;i--){
        if(!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}



int main(){
    cin>>n;
    timer = 0;
    l = ceil(log2l(n));
    g.assign(n+1, vector<int>());
    up.assign(n+1, vector<int>(l+1, -1));
    t_in.resize(n+1), t_out.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    cout<<"enter u, v\n";
    while(1){
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<"\n";
    }
    return 0;
}
