#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int idx[n], val[n];
	for(int i=0;i<n;i++)
	{
		idx[i] = i;
		cin>>val[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int bj;
		cin>>bj;
		for(int j = 0; j < n;j++)
		{
			if(j<bj)
			{
				cout<<"changing "<<idx[j]<<"to";
				idx[j] = n-bj+idx[j];
				cout<<idx[j]<<endl;
			}
			else
			{
				cout<<"changing "<<idx[j]<<"to";
				idx[j] = idx[j] - bj;
				cout<<idx[j]<<endl;
			}
		}
	}
	for(int i =0;i<n;i++)
	{
		cout<<idx[i]<<"--idxs"<<endl;
		if(idx[i]==0)
		{
			cout<<val[i]<<"--"<<endl;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
