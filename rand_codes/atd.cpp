#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fi first
#define se second
#define ii pair<int,int>
#define MP make_pair
#define vi vector<int>
#define endl "\n"
#define pb push_back
#define be begin
#define up upper_bound
#define lo lower_bound
#define bi binary_search
#define si set <int>
#define msi multiset <int>
#define vii vector <pair<int,int>>
#define mii map <int,int>
#define all(v) v.begin(),v.end()
#define mems1(a) memset(a,-1,sizeof(a))
#define mems0(a) memset(a,0,sizeof(a))
#define ci2(x1,x2) cin>>x1>>x2
#define ci3(x1,x2,x3) cin>>x1>>x2>>x3
#define ci4(x1,x2,x3,x4) cin>>x1>>x2>>x3>>x4
#define co1(x) cout<<x<<endl
#define co2(x1,x2) cout<<x1<<" "<<x2<<endl
#define co3(x1,x2,x3) cout<<x1<<" "<<x2<<" "<<x3<<endl
#define co4(x1,x2,x3,x4) cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl
#define rep(i,s,e) for(int i=s;i<e;i++)
#define rrep(i,s,e) for(int i=s-1;i>=e;i--)
#define floo(a,n) for(int i=0;i<n;i++)cin>>a[i];
using namespace std;
void solve(){
    int n;
 cin>>n;
 vector<int>a(n);
 rep(i,0,n){
    cout<<"helloo1";
    cin>>a[i];
 }
 vector<string>s(n);

 rep(i,0,n){
    cout<<"hello";
    cin>>s[i];
 }


 int q;
 cin>>q;
 vector<int>u(q),v(q);
 rep(i,0,q){
 cin>>u[i]>>v[i];
 }
 int dist[n+5][n+5];
 for(int i=0;i<=n;i++){
 for(int j=0;j<=n;j++){
 if(i!=j)dist[i][j]=1e18;
 }
 }
 int w=1e13;
 for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
 if(s[i][j]=='Y')dist[i][j]=w-a[j];
 }
 }
 for(int k=0;k<n;k++){
 for(int i=0;i<n;i++){
 for(int j=0;j<n;j++){
 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
 }
 }
 }
 for(int i=0;i<q;i++){
 cout<<dist[u[i]-1][v[i]-1]+a[u[i]-1]<<endl;
 }
}
signed main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t=1;
//  cin>>t;
 for(int i=0; i<t; i++)
 {
 solve();
 }
}