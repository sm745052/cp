#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int m= INT_MIN;
	for(int i=0;i<n-1;i++)
	{
		m = max(arr[i]-arr[i+1], m);
	}
	m = max(arr[n-1] - arr[0], m);
	for(int i=1;i<n;i++)
        {
                m = max(arr[i]-arr[0], m);
        }
	for(int i=0;i<n-1;i++)
        {
                m = max(arr[n-1]-arr[i], m);
        }
	cout<<m<<endl;
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
