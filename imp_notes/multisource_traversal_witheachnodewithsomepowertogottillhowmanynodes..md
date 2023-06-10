## Multisource BFS type traversal where each source has some max length that it can travel

```cpp
void solve(int kkk){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    map<int, int> power;
    for(int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        power[a] = b;
    }
```
Here d array mantains the max distance that it can travel after reaching that node. We always travel to that node from where we can go to max distance.
Queue element consist of the the {distance it can go if we travel to node i, node i}. we mantain a priority queue to get to that node.
implementation like dijkstra but logic is not.
logic is that it is always benefecial to go through a node with max moving distance to get to as far as possible
```cpp
    priority_queue<ii, vector<ii>> pq;
    vector<int> d(n+1, -1);
    for(auto i:power){
        pq.push({i.S, i.F});
        d[i.F] = i.S;
    }
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        if(d[t.S]!=t.F)continue;
        for(auto i:g[t.S]){
            if(d[i]<t.F-1){
                d[i] = t.F-1;
                pq.push({d[i], i});
            }
        }
    }
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(d[i]!=-1)res.pb(i);
    }
    cout<<res.size()<<"\n";
    v_print(res);
}

```
