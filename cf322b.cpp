#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r, g, b;
	cin>>r>>g>>b;
	int ctr = 0;
	while(true)
	{
		if(r>0 && g>0 && b>0)
		{
			r--;
			g--;
			b--;
			ctr++;
			continue;
		}
		if(r>=3)
		{
			r -= 3;
			ctr++;
			continue;
		}
		if(g>=3)
                {
                        g -= 3;
                        ctr++;
                        continue;
                }
		if(b>=3)
                {
                        b -= 3;
                        ctr++;
                        continue;
                }
		break;
	}
	cout<<ctr<<endl;
	return 0;
}
