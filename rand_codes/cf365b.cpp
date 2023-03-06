#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int narr[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(n==1)
	{
		cout<<1<<endl;return 0;
	}
	if(n==2)
	{
		cout<<2<<endl;return 0;
	}
	int c = 0;
	int ans = 2;
	for(int i=2;i<n;i++)
	{
		if(arr[i] == arr[i-1]+arr[i-2])
		{
			c++;
		}
		else
		{
			ans = max(ans, c+2);
			c = 0;
		}
	}
	cout<<max(ans, c+2)<<endl;
	return 0;
}
