#include <bits/stdc++.h>
using namespace std;
#define int long long



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






void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> pre(n+1, 0);
    for (auto &i : a)
    {
        cin >> i;        
    }
    set<int>qs;
    vector<pair<int, int>> lr;
    vector<int>b(n, 0);
    segtree sg(b);
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        if(k==1){
            int l, r;
            cin>>l>>r;
            l--, r--;
            sg.update(l, r, 1);
        }
        if(k==2){
            int j;
            cin>>j;
            j--;
            int x = sg.query(j, j);
            int tt = a[j];
            while(x--){
                int s = 0;
                while(tt>0){
                    int d = tt%10;
                    s+=d;
                    tt/=10;
                }
                tt=s;
                if(tt/10==0)break;
            }
            cout<<tt<<endl;
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
