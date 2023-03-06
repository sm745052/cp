#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a, b, m;
		cin>>a>>b>>m;
		long long tmp = abs(a-b);
		cout<<min(tmp, m-tmp)<<endl;
	}
	return 0;
}
