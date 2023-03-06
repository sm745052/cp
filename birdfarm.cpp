#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int x, y, z;
	cin>>x>>y>>z;
	int c1=0, c2=0;
	if(z%x==0)c1=1;
	if(z%y==0)c2=1;
	if(c1==0 && c2==1)cout<<"DUCK"<<endl;
	if(c1==1 && c2==0)cout<<"CHICKEN"<<endl;
	if(c1==0 && c2==0)cout<<"NONE"<<endl;
	if(c1==1 && c2==1)cout<<"ANY"<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
