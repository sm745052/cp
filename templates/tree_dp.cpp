vector<vector<int> > g;
vector<int> par, sz;
vector<int> idp, odp;
 
void root(int id, int pa){
    par[id] = pa;
    sz[id] = 1;
    for(auto i:g[id]){
        if(i!=pa)root(i, id), sz[id] += sz[i];
    }
}
 
void f1(int id, int pa){
    idp[id] = ... ;
    for(auto i:g[id]){
        if(i==pa)continue;
        f1(i, id);
        idp[id] += ... ;
    }
}
 
void f2(int id, int pa){
    if(pa==0){
        odp[id] = 0;
    }
    else{
        odp[id] += ... ;
    }
    for(auto i:g[id])if(i!=pa)f2(i, id);
}
