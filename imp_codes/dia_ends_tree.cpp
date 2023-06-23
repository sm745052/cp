vector<int> dia(vector<vector<int>>&g){
    vector<int> vis(g.size(), -1);
    bfs(1, g, vis);
    int md = -1;
    int d1 = arg_max(vis);
    vis.assign(g.size(), -1);
    bfs(d1, g, vis);
    int d2 = arg_max(vis);
    return {d1, d2};
}
