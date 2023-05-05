// ref: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
// run a BFS but BFS cannot handle repeating a node
// let queue elements be pair of (node and all the nodes that it has travelled [in form of a bitset])
// insert the first element from which all paths start
// the fire will expand in this case also.
// however the fire here can go backwards also even if the node has been visited but the nodes it has visited through this time is not the same as previous.
// think of a situation where we encounter that the present node and the past nodes have been encountered in the past. That means the skeleton of the path is same but there is one unnecessary loop in between this time. hence we ignore this state.
// the above prevents us to be stuck in a loop.
// i also wanted the length of the paths, hence i am adding in vis itself.



pair<int, int> st = {s, (1<<s)};
queue<pair<int, int>> q;
q.push(st);
map<pair<int, int>, int> vis;
vis[st] = 1;
while(!q.empty()){
    st = q.front();
    q.pop();
    for(auto i:graph[st.first]){
        auto cpst = st;
        cpst.S = ((cpst.S)|(1<<i));
        cpst.F = i;
        if(!vis[cpst]){
            vis[cpst] = vis[st]+1;
            q.push(cpst);
        }
    }
}
