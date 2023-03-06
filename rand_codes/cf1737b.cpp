#include<bits/stdc++.h>
using namespace std;


void solve()
{
    long long l, r;
    cin>>l>>r;
    long long a = ceil(sqrt(l));
    long long b = floor(sqrt(r));
    long long tmp = b - a + 1;
    long long cnt = tmp + 2*(tmp-1);
    if(l<=a*a-1)cnt++;
    if(l<=(a*a+(a-1)*(a-1))/2)cnt++;
    if(r>=(b*b+(b+1)*(b+1))/2)cnt++;
    if(r==((b+1)*(b+1)-1))cnt++;
    cout<<cnt<<endl;
}


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}