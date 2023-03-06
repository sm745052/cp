#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string t;
	cin>>t;
	int n;
	cin>>n;
	string s[];
	int l[];
	int f[];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		l[i] = s[i].length();
		auto k = t.find(s[i]);
		if (k != string::npos)
		{
			f[i] = k;
		}
		else
		{
			f[i] = -1;
		}
	}
}




int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
