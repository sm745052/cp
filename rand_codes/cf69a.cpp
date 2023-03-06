#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int n_x = 0, n_y = 0, n_z = 0;
	while(n--)
	{
		int x, y, z;
		cin>>x>>y>>z;
		n_x += x;
		n_y += y;
		n_z += z;
	}
	if(n_x == 0 && n_y == 0 && n_z == 0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
