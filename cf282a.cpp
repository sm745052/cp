#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int c = 0;
	while(n--)
	{
		string s;
		cin>>s;
		if('+' == s[0] || '+'==s[2])
		{
			c++;
		}
		else
		{
			c--;
		}
	}
	cout<<c<<endl;
	return 0;
}
