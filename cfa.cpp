#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ctr = 0;
    for (auto &i : a)
    {
        cin >> i;
        if (i == 1)
            ctr++;
    }
    cout << (ctr / 2) + ctr % 2 + (n - ctr) << endl;
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
