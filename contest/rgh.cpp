#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define pp pair<ll,ll>
#define ll int
#define True 1
#define gcd __gcd
#define range(i,a,b,c) for(ll i=a;i<b;i+=c)
#define int long long
#define lb lower_bound
#define ub upper_bound
#define False 0
#define prmap(m) {for(auto i: m) cout<<(i.fi)<<": "<<i.sec<<"  "; print("")}
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define pq priority_queue<int>
#define all(v) v.begin(),v.end()
#define len(p) p.size()
#define append pb
#define foi(p,n) for(int i=p;i<n;i++)
#define ini(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define fi first
#define sec second
#define mp make_pair
#define tc while(t--)
#define N ((ll)200009)
#define gtc(a,b) cout<<"Case #"<<a<<": "<<b<<endl;
#define va(n) vector<ar<ll,n>>
#define fo(n) for(int i=0;i<n;i++)
#define rev(n) for(int i=n-1;i>=0;i--)
#define foj(m,n) for(int j=m;j<n;j++)
#define ar array
#define vp vector<pair<int,int>>
#define vc vector<int>
#define print(p) cout<<p<<"\n";
#define pr(p) cout<<p<<" ";
#define pr2(p,q) cout<<p<<" "<<q<<endl;
#define pr3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pr4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define pra(a) {for(auto i: a) cout<<i<<" "; cout<<endl;}
#define prm(a) {for(auto i: a) pra(i) cout<<endl;}
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define isvalid(i,j,n,m) (1<=i and i<=n and 1<=j and j<=m)
#define gh fflush(stdout)
#define why {print("LOL") return 0;}
using namespace std;

ll n,t,k,maxn,x,y,flag=0,l1,r1,l2,r2,parity[2]={0,0},ok,q,need,p,c=0;
ll mod=1e9+7,INF=1e18;

vc a[2005];
ll col[2005],vis[2005][2005];


signed main()
{
fio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("all.txt", "w", stdout);
#endif

t=1;
cin>>t;
ll uu=t;



tc{ 
	ll m;
	cin>>n>>m;
	foi(1,n+1) cin>>col[i];
	fo(n+1) a[i].clear();
	fo(n+1) foj(0,n+1) vis[i][j]=0;
	fo(m){
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	if(col[1]==col[n]){
		print(-1)
		continue;
	}
	ll ans=-1;
	queue<ar<ll,3>> q;
	q.push({1,n,0});
	vis[1][n]=2;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(u[0]==n and u[1]==1){
			ans=u[2];
			break;
		}
		for(ll j: a[u[0]])
			for(ll k: a[u[1]])
				if(col[j]!=col[k] and vis[j][k]==0){
					vis[j][k]=1;
					q.push({j,k,u[2]+1});
				}
	}
	while(!q.empty()) q.pop();
	print(ans)
}

return 0;}