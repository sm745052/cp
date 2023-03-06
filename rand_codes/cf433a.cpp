#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a=0, b=0;
	while(n--)
	{
		int tmp;
		cin>>tmp;
		if(tmp==100)a++;
		else b++;
	}
	for(int p=0;p<=a;p++)
	{
		for(int q=0;q<=b;q++)
		{
			if(2*p+4*q == a+2*b)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
