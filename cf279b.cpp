#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n, t;
	cin>>n>>t;
	int A[n];
	long sum_A[n+1] = {0};
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		sum_A[i+1] = sum_A[i] + A[i];
	}
	int j=1;
	vector<long> tmp;
	for(int i=1;i<n+1;i++)
	{
		while(j<n+1 && sum_A[j] - sum_A[i-1] <= t)
		{
			j++;
		}
		j--;
		tmp.push_back(j-i+1);
	}
	cout<<*max_element(tmp.begin(), tmp.end())<<endl;
	return 0;
}
