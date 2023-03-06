#include<bits/stdc++.h>
using namespace std;
#define long long long int
int main()
{
	long n;
	cin>>n;
	long v[n];
	long u[n];
	for(long i=0;i<n;i++)
	{
		cin>>v[i];
		u[i] = v[i];
	}
	sort(u, u+n);
	vector<long> sumv, sumu;
	sumv.push_back(0);
	sumu.push_back(0);
	for(long i=0;i<n;i++)
	{
		sumv.push_back(sumv[sumv.size()-1] + v[i]);
		sumu.push_back(sumu[sumu.size()-1] + u[i]);
	}
	long m;
	cin>>m;
	while(m--)
	{
		int type, l, r;
		cin>>type>>l>>r;
		if(type == 1)
		{
			cout<<sumv[r] - sumv[l-1]<<endl;
		}
		else
		{
			cout<<sumu[r] - sumu[l-1]<<endl;
		}
	}
	return 0;
}
