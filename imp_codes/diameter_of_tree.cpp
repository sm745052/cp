// take any node, get to the node with max distance from this node.
// this node is now a leaf.
// find the node with max distance again from the new node. the distance is the diameter.


int dia(int id){
    queue<int> q;
    q.push(id);
    vector<int> vis(n+1, 0);
    vis[id] = 1;
    int s;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(auto i:g[s]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    q = queue<int>();
    q.push(s);
    vis = vector<int>(n+1, 0);
    vector<int> d(n+1, INT_MAX);
    d[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(auto i:g[s]){
            if(!vis[i]){
                vis[i]=1;
                d[i] = d[s]+1;
                q.push(i);
            }
        }
    }
    return d[s];
}
