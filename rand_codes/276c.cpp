#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long n_arr[n+1] = {0};
	for(int i=0;i<q;i++)
	{
		int l, r;
		cin>>l>>r;
		n_arr[l-1]++;
		n_arr[r]--;
	}
	long long acc = 0;
	for(int i=0;i<n+1;i++)
	{
		acc += n_arr[i];
		n_arr[i] = acc;
	}
	sort(arr, arr+n, greater<int>());
	sort(n_arr, n_arr+n+1, greater<long long>());
	long long sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i] * n_arr[i];
	}
	cout<<sum<<endl;
	return 0;
}
