#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int arr[n][2];
	int neg_x=0, pos_x=0, neg_y=0, pos_y=0;
	int x[n], y[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0];
		cin>>arr[i][1];
		x[i] = (arr[i][0]);
		y[i] = (arr[i][1]);

		(x[i]<0 && neg_x>x[i])?neg_x=x[i]:1;
		(x[i]>0 && pos_x<x[i])?pos_x=x[i]:1;
		(y[i]<0 && neg_y>y[i])?neg_y=y[i]:1;
                (y[i]>0 && pos_y<y[i])?pos_y=y[i]:1;

	}
	//cout<<neg_x<<" "<<neg_y<<" "<<pos_x<<" "<<pos_y<<endl;
	cout<<2*(abs(neg_x)+abs(neg_y)+abs(pos_x)+abs(pos_y))<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
