#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
	int sum_H[n+1]={0};
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		sum+=tmp;
		sum_H[i] = sum;
	}
	int min = sum_H[n];
	int pos = -1;
	for(int i=1;i<=n+1-k;i++)
	{
		int tmp = sum_H[i+k-1] - sum_H[i-1];
		if(tmp<min)
		{
			 min = tmp;
			pos = i;
		}
	}
	if(n==k)cout<<1<<endl;
	else cout<<pos<<endl;
	return 0;
}
