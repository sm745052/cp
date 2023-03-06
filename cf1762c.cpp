#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=1;
    int po2=-1;
    int ctr0=(s[0]=='0'), ctr1=(s[0]=='1');
    int lsame = 0;
    int p_ans=ans;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            p_ans=1;
        }
        else{
            p_ans = (p_ans*2)%998244353;
        }
        ans =(ans + p_ans)%998244353;
        
    }
    cout<<ans<<endl;
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