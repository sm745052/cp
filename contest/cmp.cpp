#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
#define ls now<<1
#define rs now<<1|1
ll sum[N<<2],mx[N<<2];
int a[N],n,B,q,p,x;
void pushup(int now){
	mx[now]=max(mx[ls],mx[rs]+sum[ls]);
	sum[now]=sum[ls]+sum[rs];
}
void build(int now, int l, int r){
	if (l==r) return mx[now]=sum[now]=a[l],void();
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
ll query(int now, int l, int r, int x){
	if (l==r) return sum[now];
	int mid=(l+r)>>1;
	if (mid>=x) return query(ls,l,mid,x);
	else return sum[ls]+query(rs,mid+1,r,x);
}
int Find(int now, int l, int r, ll d){
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (mx[ls]>=d) return Find(ls,l,mid,d);
	else return Find(rs,mid+1,r,d-sum[ls]);
}
void update(int now, int l, int r, int x){
	if (l==r) return mx[now]=sum[now]=a[l],void();
	int mid=(l+r)>>1;
	if (mid>=x) update(ls,l,mid,x);
	else update(rs,mid+1,r,x);
	pushup(now);
}
int main(){
	scanf("%d%d%d",&n,&B,&q);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]-=B;
	build(1,1,n);
	for (; q; q--){
		scanf("%d%d",&p,&x); a[p]=x-B;
		update(1,1,n,p);
		if (mx[1]<0) printf("%.15lf\n",1.0*sum[1]/n+B);
		else {
			int d=Find(1,1,n,0);
			printf("%.15lf\n",1.0*query(1,1,n,d)/d+B);
		}
	}
}