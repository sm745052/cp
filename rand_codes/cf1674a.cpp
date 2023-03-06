#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int x, y;
		cin>>x>>y;
		if((y/x)*x == y)
		{
			cout<<1<<' '<<(y/x)<<endl;
		}
		else
		{
			cout<<"0 0\n";
		}
	}
	return 0;
}
