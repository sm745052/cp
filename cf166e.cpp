#include<bits/stdc++.h>
using namespace std;

long long f(int n)
{
	const unsigned int M = 1000000007;
	long long tmp = 0;
	long long tmp_3 = 1;
	for(int i=2;i<=n;i++)
	{
		tmp_3 = (tmp_3*3) % M;
		tmp = (tmp_3 - tmp)%M;
	}
	return (tmp>=0?tmp:M+tmp);
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}
