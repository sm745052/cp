#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s, t;
		cin>>s>>t;
		int ctr1 = 0, ctr2 = 0;
		for(int i = 0;i<t.length();i++)
		{
			if(t[i] == 'a')
			{
				ctr1 = 1;
			}
		}
		if(ctr1 == 0)
		{
			cout<<long(pow(2, s.length()) + .5)<<endl;
		}
		else
		{
			if (t.length()==1)
				cout<<1<<endl;
			else
				cout<<-1<<endl;
		}
	}
	return 0;
}
