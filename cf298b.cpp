#include<bits/stdc++.h>
using namespace std;
int main()
{
	long t, sx, sy, ex, ey;
	cin>>t>>sx>>sy>>ex>>ey;
	long net_x = ex-sx;
	long net_y = ey-sy;
	long initial = t;
	while(t--)
	{
		char w;
		cin>>w;
		switch(w)
		{
			case 'E':
				if(net_x>0)
				{
					net_x--;
				}
				break;
			case 'W':
				if(net_x<0)
                                {
                                        net_x++;
                                }
                                break;
			case 'N':
                                if(net_y>0)
                                {
                                        net_y--;
                                }
                                break;
                        case 'S':
                                if(net_y<0)
                                {
                                        net_y++;
                                }
                                break;
		}
		if(net_x == 0 && net_y ==0)
		{
			cout<<initial - t<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
