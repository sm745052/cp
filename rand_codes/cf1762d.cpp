#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 

int query(int i, int j){
    cout<<"? "<<i<<" "<<j<<endl;
    int k;
    cin>>k;
    cout.flush();
    return k;
}

 
 
void solve(){
    int n;
    cin>>n;
    int i=1, j=2;
    int g = query(i, j);
    if(n==2){
        cout<<"! "<<i<<" "<<j<<endl;
        int res;
        cin>>res;
        return;
    }
    for(int x=3;x<=n;x++){
        int g1 = query(i, x), g2 = query(j, x);
        if(g1>max(g, g2)){
            i=x;
            g=g1;
        }
        else{
            if(g2>max(g, g1)){
                j=x;
                g = g2;
            }
        }
    }
    cout<<"! "<<i<<" "<<j<<endl;
    int res;
    cin>>res;
    return;
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