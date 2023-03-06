#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first==b.first)
	{
		return a.second<b.second;
	}
	return a.first<b.first;
}
int main()
{
	int n;
	cin>>n;
	pair<int, int> arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+n, cmp);
	if(n==1)
	{
		cout<<arr[0].second<<endl;
		return 0;
	}
	if(arr[n-1].second>=arr[n-2].second)
		cout<<arr[n-1].second<<endl;
	else
		cout<<arr[n-1].first<<endl;
	return 0;
}
