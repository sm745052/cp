# Sqrt decomposition

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bs = (int)sqrt(n+0.0) + 1;
    vector<int> b(n/bs + 1, INT_MIN), a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i/bs] = max(a[i], b[i/bs]);
    }
    int q;
    cin>>q;
    while(q--){
        int l; int r;
        cin>>l>>r;
        l--, r--;
        int res = INT_MIN;
        for(int i=l;i<=r;){
            if(i%bs==0 && i+bs-1<=r){
                res = max(res, b[i/bs]);
                i+=bs;
            }
            else{
                res = max(res, a[i]);
                i++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
```

## Note
We can set block size to any thing (Except 0) and set length of the blocks array to (n/bs + 1). but when done to sqrt(n) it is optimized.
This is done when merging the blocks is easy. When it is hard, we can see MO's algorithm.

below is implementation of MO's algo to find mode of a range query
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bs = (int)sqrt(n+0.0) + 1;
    vector<int> b(n/bs + 1, INT_MIN), a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int q;
    cin>>q;
    using ii=pair<int, int>;
    vector<pair<int, ii>> queries;
    int i=0;
    while(q--){
        int l; int r;
        cin>>l>>r;
        l--, r--;
        queries.push_back({i, {l, r}});
        i++;
    }
    vector<int> ans(queries.size());
#define S second
#define F first
    sort(queries.begin(), queries.end(), [&](pair<int, ii> a, pair<int , ii> b)->bool{
        if(a.S.F/bs==b.S.F/bs){
            return a.S.S<b.S.S;
        }
        return a.S.F/bs==b.S.F/bs;
    });
    int head = -1, tail = 0;
    set<ii> st;
    map<int, int> f;
    for(int i=0;i<queries.size();i++){
        auto qu = queries[i];
        int qid = qu.F;
        int l = qu.S.F;
        int r = qu.S.S;
        while(head<r){
            head++;
            int fr = f[a[head]];
            st.erase({fr, a[head]});
            f[a[head]]++;
            st.insert({fr+1, a[head]});
        }
        while(tail<l){
            int fr = f[a[tail]];
            st.erase({fr, a[tail]});
            f[a[tail]]--;
            st.insert({fr-1, a[i]});
            tail++;
        }
        while(head>r){
            int fr = f[a[head]];
            st.erase({fr, a[head]});
            f[a[head]]--;
            st.insert({fr-1, a[i]});
            head--;
        }
        while(tail>l){
            tail--;
            int fr = f[a[tail]];
            st.erase({fr, a[tail]});
            f[a[tail]]++;
            st.insert({fr+1, a[tail]});
        }
        ans[qu.F] = st.rbegin()->second;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
```
