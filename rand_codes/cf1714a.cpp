#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n, H, M;
	cin>>n>>H>>M;
	int t[n];
	int tm = H*60+M;
	for(int i=0;i<n;i++)
	{
		int h, m;
		cin>>h;
		cin>>m;
		t[i] = (h*60+m>=tm)?h*60+m:24*60+h*60+m;
	}
	sort(t, t+n);
	int ts = *lower_bound(t, t+n, tm) - tm;
	H = ts/60;
	M = ts%60;
	cout<<H<<" "<<M<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
