#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p = 0;
	int cap = 0;
	while(n--)
	{
		int a, b;
		cin>>a>>b;
		p += b-a;
		cap = max(cap, p);
	}
	cout<<cap<<endl;
	return 0;
}
