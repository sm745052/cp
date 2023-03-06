#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ctr = 0;
    map<int, int> pos;
    for (auto &i : a)
    {
        cin >> i;
        pos[i]=ctr;
        ctr++;
    }
    int lctr=0, rctr=0;
    if(n%2==0){
        int li=n/2, ri = n/2+1;
        while(li>=1 && pos[li]<pos[li+1])lctr++, li--;
        while(ri<=n && pos[ri]>pos[ri-1])rctr++, ri++;
        li++;
        ri--;
        cout<<li<<"-="<<ri<<endl;
        cout<<(n-(2*min(ri-(n/2+1), n/2-li)))/2<<endl;
    }
    else{
        int li=n/2, ri = n/2+2;
        while(li>=1 && pos[li]<pos[li+1])lctr++, li--;
        while(ri<=n && pos[ri]>pos[ri-1])rctr++, ri--;
        cout<<n-(2*min(li, ri)+1)<<endl;
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

