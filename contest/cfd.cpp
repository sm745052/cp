#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
vector<bool> vis;
vector<int>twos, fives;
int n, k;


int rec(int lev, int rem){
    if(rem<=0)return 0;
    if(lev>=n)return -1e9;
    vis[lev]=1;
    int a1 = rec(lev+1, rem-1);
    vis[lev]=0;
    int a2 = rec(lev+1, rem);
    return max(a1, a2);
}




void solve(){
    int n, k, x;
    cin>>n>>k>>x;
    vector<int> arr(n), pre(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pre[i] = arr[i];
        if(i)pre[i]+=pre[i-1];
    }
    int head = -1, tail = 0;
    int ml=INT_MIN, ms=INT_MIN, mh, mt;
    while(tail<n){ 
        while(arr[head+1]>0 && head<n){
            head+=1;
        }
        if(ms<pre[head] - ((tail==0)?0:pre[tail-1])){
            ms = pre[head] - ((tail==0)?0:pre[tail-1]);
            mh = head, mt = tail;
        }
        

        tail+=1;
    }
}

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
