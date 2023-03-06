#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[3002]={0};
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		arr[k]=1;
	}
	for(int i=1;i<=3001;i++)
	{
		if(!arr[i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
