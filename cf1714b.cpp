#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int a[n];
	int f[n];
	map<int, int> g1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		g1[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		f[i] = g1[a[i]]--;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(f[i]!=1)
		{
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<0<<endl;
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

