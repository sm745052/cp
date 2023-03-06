#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%10==5)
		{
			a[i] += 5;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i] != a[i-1])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	for(int i=0;i<n;i++)
	{
		
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
