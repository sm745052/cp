#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	pair<int, int> arr[100001];
	for(int i =0;i<100001;i++)
	{
		arr[i] = make_pair(INT_MAX, INT_MIN);
	}
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin>>a>>b;
		arr[a].first = min(arr[a].first, b);
		arr[a].second = max(arr[a].second, b);
	}
	for(int i=1;i<100000;i++)
	{
		if(arr[i].second>arr[i+1].first)
		{
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}
	cout<<"Poor Alex"<<endl;
	return 0;
}
