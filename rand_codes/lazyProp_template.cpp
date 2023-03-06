#include<bits/stdc++.h>
using namespace std;


class segtree{
public:
    int n;
    vector<int> t, tl;
    vector<int> arr;

    segtree(vector<int> arr_){
        n = arr_.size();
        arr = arr_;
        t.resize(4*n);
        tl.resize(4*n);
        build_(1, 0, n-1);
        buildLazy_(1, 0, n-1);
    }


    int query(int ql, int qr){
        return query_(1, 0, n-1, ql, qr);
    }

    void update(int ql, int qr, int val){
        update_(1, 0, n-1, ql, qr, val);
    }


private:
    void build_(int id, int l, int r){
        if(l==r){
            t[id] = arr[l];
        }
        else{
            int mid = (l+r)/2;
            build_(2*id, l, mid);
            build_(2*id+1, mid+1, r);
            // """MERGE"""
            t[id] = min(t[2*id], t[2*id+1]);
        }
    }


    void buildLazy_(int id, int l, int r){
        if(l==r){
            tl[id] = 0;
        }
        else{
            int mid = (l+r)/2;
            build_(2*id, l, mid);
            build_(2*id+1, mid+1, r);
            tl[id] = 0;
        }
    }


    int query_(int id, int l, int r, int ql, int qr){
        if(ql<=l && qr>=r){
            int v = tl[id];
            if(l!=r){
                tl[2*id] += v;
                tl[2*id+1] += v;
            }
            tl[id]=0;
            t[id] += v;
            return t[id];
        }
        if(ql>r || qr<l){
            // """overflow conditions"""
            return INT_MAX;
        }
        int mid = (l+r)/2;
        tl[2*id]+=tl[id];
        tl[2*id+1]+=tl[id];
        tl[id]=0;
        int v = min(query_(2*id, l, mid, ql, qr), query_(2*id+1, mid+1, r, ql, qr));
        t[id] = min(t[2*id], t[2*id]+1);
        return v;
    }
    void update_(int id, int l, int r, int ql, int qr, int val){
        if(l>=ql && r<=qr){
            t[id] += tl[id]+val;
            if(l!=r){
                tl[2*id+1]+=tl[id]+val;
                tl[2*id]+=tl[id]+val;
            }
            tl[id] = 0;
            return;
        }
        if(l>qr || r<ql){
            return;
        }
        int mid = (l+r)/2;
        update_(2*id, l, mid, ql, qr, val);
        update_(2*id+1, mid+1, r, ql, qr, val);
        // """MERGE"""
        t[id] = min(t[2*id], t[2*id+1]);
    }
};






int main(){
    vector<int>a(3);
    a = {1, 2, 3};
    segtree sg(a);
    sg.update(0, 2, 3);
    sg.update(1, 2, 1);
    cout<<sg.query(0, 0)<<endl;
    cout<<sg.query(1, 1)<<endl;
    cout<<sg.query(2, 2)<<endl;
    cout<<sg.query(0, 2)<<endl;
    for(auto i:sg.t){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:sg.tl){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}