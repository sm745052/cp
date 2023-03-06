#include<bits/stdc++.h>
using namespace std;

# define int long long

template<class T>
class segtree{
public:
    int n;
    vector<T> t;
    vector<T> arr;
    function<T(T, T)> op;
    function<T()> e;

    segtree(vector<T> arr_, function<T(T, T)> operation, function<T()> identity){
        n = arr_.size();
        arr = arr_;
        op = operation;
        e = identity;
        t.resize(4*n);
        build_(1, 0, n-1);
    }


    T query(int ql, int qr){
        return query_(1, 0, n-1, ql, qr);
    }

    void update(int pos, T val){
        update_(1, 0, n-1, pos, val);
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
            t[id] = op(t[2*id], t[2*id+1]);
        }
    }

    T query_(int id, int l, int r, int ql, int qr){
        if(ql<=l && qr>=r){
            return t[id];
        }
        if(ql>r || qr<l){
            return {0, -1e9};
        }
        int mid = (l+r)/2;
        return op(query_(2*id, l, mid, ql, qr), query_(2*id+1, mid+1, r, ql, qr));
    }

    void update_(int id, int l, int r, int pos, T val){
        if(l==r){
            t[id] = val;
            arr[l] = val;
            return;
        }
        int mid = (l+r)/2;
        if(mid>=pos){
            update_(2*id, l, mid, pos, val);
        }
        else{
            update_(2*id+1, mid+1, r, pos, val);
        }
        // """MERGE"""
        t[id] = op(t[2*id], t[2*id+1]);
    }
};


signed main(){
    cout<<setprecision(20);
    int n, b, q;
    cin>>n>>b>>q;
    vector<pair<int, int>>a(n);
    for(auto &i:a){
        int kk;
        cin>>kk;
        i = {kk-b, kk-b};
    }
    segtree<pair<int, int>> sg(a, [](pair<int, int>a, pair<int, int>b){return (pair<int, int>){a.first+b.first, max(a.second, a.first+b.second)};}, [](){return (pair<int, int>){0, -1e9};});
    for(int i=0;i<q;i++){
        int x, c;
        cin>>c>>x;
        sg.update(c-1, {x-b, x-b});
        int lo=0, hi=n-1;
        int ans = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(sg.query(0, mid).second >= 0){
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1;
            }
        }
        // cout<<ans<<endl;
        cout<<(((1.0)*(sg.query(0, ans).first + b*(ans+1)))/(ans+1))<<endl;
    }
    return 0;
}