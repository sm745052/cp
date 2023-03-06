#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int x=0;
	x = (n/5)*4 + n - (n/5)*5;
	cout<<x<<endl;
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
