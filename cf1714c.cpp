#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int s;
	cin>>s;
	vector<int> d;
	int ctr = 9;
	while(s>0)
	{
		if(s-ctr>0)
		{
			d.push_back(ctr);
			s -= ctr;
			ctr--;
		}
		else
		{
			d.push_back(s);
			break;
		}
	}
	sort(d.begin(), d.end());
	for(int i=0;i<d.size();i++)
	{
		cout<<d[i];
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
