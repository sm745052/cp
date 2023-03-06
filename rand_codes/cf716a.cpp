#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{
	int n, c;
	cin>>n>>c;
	int arr[n];
	int ctr = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(i==0)ctr++;
		else
		{
			if(arr[i]-arr[i-1]<=c)ctr++;
			else ctr=1;
		}
	}
	cout<<ctr<<endl;
	return 0;
}

