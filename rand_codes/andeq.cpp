#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	long long A[n];
	cin>>A[0];
	long long res = A[0];
	for(int i=1;i<n;i++)
	{
		cin>>A[i];
		res = res & A[i];
	}
	int no = 0;
	int ctr = 0;
	int tmp = A[0];
	while(true)
	{
		tmp = tmp & A[ctr];
		if(tmp == res)
		{
			no++;
			if(ctr<n-1)
				tmp = A[ctr+1];
		}
		ctr++;
		if(ctr>=n)break;
	}
	cout<<(n - no)<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
