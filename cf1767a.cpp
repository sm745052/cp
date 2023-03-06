#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
void solve(){
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    if(a==c && b==f || a==e && b==d || c==a && d==f || c==e && d==b || e==a && f==d || e==c && f==b){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
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