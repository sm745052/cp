#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    n = 4;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int l = a[0];
    int t = 2*a[0];
    l-=min(l, a[2]);
    a[2]-=min(l, a[2]);
    if(l==0){
        
    }
    cout<<ans<<endl;
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
