#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t[n];
	int consc = 1;
	int max_consc = 1;
	for(int i=0;i<n;i++)
	{
		int h, s;
		cin>>h>>s;
		t[i] = 60*h + s;
		if(i==0) continue;
		if(t[i]-t[i-1]<1)
		{
			consc++;
		}
		else
		{
			max_consc = max(max_consc, consc);
			consc = 1;
		}
	}
	cout<<max(max_consc, consc)<<endl;
	return 0;
}
