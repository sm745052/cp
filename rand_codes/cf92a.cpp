#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 1;;i++)
	{
		if(i>n)
		{
			i = 1;
		}
		if(m-i>=0)
		{
			m-=i;
		}
		else
		{
			break;
		}
	}
	cout<<m<<endl;
	return 0;
}
