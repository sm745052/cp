#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int, int> g1;
	int maxi = -1 ;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		g1[k]++;
		maxi = max(maxi, k);
	}
	long long f[maxi+1] = {0};
	int flag = 0;
	int l = 0;
	for(auto& i:g1)
	{
		if(flag == 0)
		{
			f[i.first] = i.first*i.second;
			flag = 1;
			l = i.first;
			continue;
		}
		for(int j = l+1;j<=i.first-2;j++)
		{
			f[j] = f[l];
		}
		l = i.first;
		f[i.first] = max(i.first*i.second+f[i.first-2], f[i.first-1]);
	}
	cout<<f[maxi]<<endl;
	return 0;
}
