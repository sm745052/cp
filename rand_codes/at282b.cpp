#include<bits/stdc++.h>

using namespace std;
vector<int> G[200005];
int color[200005];

int main(){
    int n, m;
    cin>>n>>m;
    int u, v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = (n*(n-1))/2 -m;
    for(int i=1;i<=n;i++){
        
    }
    return 0;
}