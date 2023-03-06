#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n], sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(sum == n*arr[i])
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
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
