#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int arr[n];
	int used[n] = {0};
	vector<int> fin;
	int ctr1 = 0;
	int ctr2 = n-1;
	int flc = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+n);
	fin.push_back(arr[0]);
	ctr1++;
	flc++;
	for(int i=1;i<n;i++)
	{
		if(flc%2==0)
		{
			if(arr[ctr1] == arr[ctr2+1])
			{
				cout<<"NO"<<endl;
				return;
			}
			fin.push_back(arr[ctr1]);
			ctr1++;
		}
		else
		{
			if(arr[ctr1-1] == arr[ctr2])
			{
				cout<<"NO"<<endl;
				return;
			}
			fin.push_back(arr[ctr2]);
			ctr2--;
		}
		flc++;
	}
	if(fin[fin.size()-1] == fin[0] || fin[fin.size()-2]>=fin[fin.size()-1])
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(auto i:fin)
	{
		cout<<i<<" ";
	}
	cout<<endl;
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

