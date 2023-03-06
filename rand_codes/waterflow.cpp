#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int w, x, y, z;
	cin>>w>>x>>y>>z;
	int tmp = x-(w+y*z);
	if(tmp<0)cout<<"overflow"<<endl;
	else if(tmp==0)cout<<"filled"<<endl;
	else cout<<"unfilled"<<endl;
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
