#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define PN no()
#define PY yes()
#define v_inp(a) for(auto &i:a)cin>>i
#define v_print(a) for(int itt=0;itt<a.size();itt++)cout<<a[itt]<<" \n"[itt==a.size()-1]
#define s_print(a) for(auto itt:a)cout<<itt<<" ";cout<<endl
#define pb push_back
#define v_sort(a) sort(a.begin(), a.end());
#define v_lb(a, x) lower_bound(a.begin(), a.end(), x)
#define v_ub(a, x) upper_bound(a.begin(), a.end(), x)
#define v_accumulate(a, x) accumulate(a.begin(), a.end(), x)
#define v_e
#define rep(i, l, r) for(int i=l;i<r;i++)
template<class T>
vector<T> v_psum(vector<T> a){
    vector<T> prefix(a.begin(), a.end());
    for(int i=1;i<a.size();i++)prefix[i]+=prefix[i-1];
    return prefix;
}

void no(){
    cout<<"No"<<endl;
}
void yes(){
    cout<<"Yes"<<endl;
}
// --------------------------------------------------------------------


// white, grey, black concept
// unvisited nodes are white
// nodes in present chain is grey
// nodes who have been in a chain that is processed and cycle not found in that chain, are marked black
// black nodes cannot be in any cycle
// we keep track of present chain via parent array, needed for cycle printing





vector<vector<int>> g;
vector<int> vis;
int c_s, c_e;
vector<int> parent;

int dfs(int id){
    vis[id] = 1;
    int ans = 0;
    for(auto i:g[id]){
        if(vis[i]==1){
            c_s = i;
            c_e = id;
            return 1;
        }
        if(vis[i]==0){
            parent[i] = id;
            if(dfs(i)) return 1;
        }
    }
    vis[id] = 2;
    return 0;
}


void print_cycle(int s, int e){
    if(e != s){
        print_cycle(s, parent[e]);
    }
    cout<<e<<" ";
}


signed main(){
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}};
    int m = edges.size();
    g.resize(n+1);
    vis.resize(n+1, 0);
    parent.resize(n+1, 0);
    for(auto i:edges){
        g[i[0]].pb(i[1]);
    }
    if(dfs(1)){
        cout<<"Yes"<<endl;
        print_cycle(c_s, c_e);
        cout<<"\n";
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
