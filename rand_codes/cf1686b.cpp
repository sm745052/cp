#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n];
	int ctr = 0;
	for(int i=0;i<n;i++)
        {
		cin>>arr[i];
        }
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			ctr++;
			i++;
		}
	}
	cout<<ctr<<endl;
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
