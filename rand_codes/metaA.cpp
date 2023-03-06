#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin>>n>>k;
	map<int, int> g, g1, g2;
	int ctr1 = 0, ctr2 = 0;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		/*
		cout<<"g\n";
		for(auto &i:g)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
		cout<<"g1\n";
for(auto &i:g1)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
		cout<<"g2\n";
for(auto &i:g2)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
*/
		int key;
		cin>>key;
		if(g[key]!=2)
		{
			if(ctr1<=ctr2)
			{
				if(g1[key]==0)
	                        {
					ctr1++;
        	                        g1[key]++;
                	                g[key]++;
                       		}
                        	else if(g2[key]==0)
                        	{
					ctr2++;
                                	g[key]++;
	                                g2[key]++;
        	                }
				else
				{
					flag = 1;
				}
			}
			else if(ctr2<ctr1)
			{
				if(g2[key]==0)
				{
					ctr2++;
					g2[key]++;
					g[key]++;
				}
				else if(g1[key]==0)
				{
					ctr1++;
					g[key]++;
					g1[key]++;
				}
				else
				{
					flag = 1;
				}
			}
			if(ctr1>k ||  ctr2>k)
			{
				flag = 1;
			}
		}
		else
		{
			flag = 1;
		}
		/*
		cout<<"g\n";
                for(auto &i:g)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
                cout<<"g1\n";
for(auto &i:g1)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
                cout<<"g2\n";
for(auto &i:g2)
        {
                cout<<i.first<<"--->"<<i.second<<endl;
        }
	*/
	}
	if(flag)
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
}	



int main()
{
	int t;
	cin>>t;
	int i=1;
	while(i<=t)
	{	
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
	return 0;
}
