#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int ctr=1;
    for (auto &i : a)
    {
        cin >> i;
        i+=ctr;
        ctr++;
    }
    sort(a.begin(), a.end());
    int i;
    for(i=0;i<n;i++){
        if(q-a[i]<0)break;
        q-=a[i];
    }
    cout<<i<<endl;
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
