void bfs(int s, vector<vector<int>> &g, vector<int>& vis){
    vis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for(auto i:g[t]){
            if(vis[i]==-1){
                vis[i] = vis[t]+1;
                q.push(i);
            }
        }
    }
}
