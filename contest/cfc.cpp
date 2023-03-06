#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l, r;
    cin>>l>>r;
    int m = log2(r/double(l));
    cout<<m+1<<" ";
    int ctr=0;
    for(int i=l;i<=r;i++){
        if((int)(log2(r/double(i)))==m)ctr++;
    }
    cout<<ctr<<endl;
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
