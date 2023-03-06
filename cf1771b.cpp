#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;
    int arr[n+1]={0};
    for(int i=0;i<=n;i++)arr[i]=LLONG_MAX;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        if(y>x)
            arr[x] = min(arr[x], y);
        if(x>y)
            arr[y] = min(arr[y], x);
    }
    multiset<int>g1 = {LLONG_MAX};
    int head = 0, tail = 1;
    int ctr=0;
    while(tail<=n){
        while(head+1<=n && (*(g1.begin()))!=head+1){
            g1.insert(arr[head+1]);
            ctr++;
            head++;
        }
        auto itr = g1.find(arr[tail]);
        if(itr!=g1.end()){
            g1.erase(itr);
        }
        ctr += head-tail;
        tail++;
    }
    cout<<ctr<<endl;
}


int32_t main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}