#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string st;
		cin>>st;
		char a = st[0], b = st[1];
		if(a<b)
		{
			cout << (a - 'a') * (26 - 1) + b - 'a' + 1 - 1 <<endl;
		}
		else
		{
			cout << (a - 'a') * (26 - 1) + b - 'a' + 1 <<endl;
		}
	}
	return 0;
}
