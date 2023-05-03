// get all the leaves (degree 1)
// push them to queue
// pop first and delete the edge associated with it i.e. reduce the degree of neighbor by 1
// add new leaves if generated to queue
// last leaf extracted from queue is the center

int center(int id){
    map<int, int> deg1;
    deg1= deg;
    queue<int> q;
    q.push(id);
    vector<int> vis(n+1, 0);
    int s;
    vis[id] =1;
    queue<int>leaves;
    while(!q.empty()){
        s = q.front();
        q.pop();
        if(deg1[s]<=1){
            leaves.push(s);
        }
        for(auto i:g[s]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    vis.assign(n+1, 0);
    q = leaves;
    s = leaves.front();
    vis[s] = 1;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(auto i:g[s]){
            if(!vis[i]){
                deg1[i]--;
                if(deg1[i]==1){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    return s;
}
