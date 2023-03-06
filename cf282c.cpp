#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	cin>>a>>b;
	int a0=0, b0=0, b1=0, a1=0;
	if(a==b)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	if(a.length() != b.length())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<a.length();i++)
	{
		if(a[i] == '0')
		{
			a0++;
		}
		else
		{
			a1++;
		}
	}
	for(int i=0;i<b.length();i++)
        {
                if(b[i] == '0')
                {
                        b0++;
                }
                else
                {
                        b1++;
                }
        }
	if(a1>0 && b1>0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
