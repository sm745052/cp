#include <bits/stdc++.h>
 
using namespace std;
const int c=200005;
int t[c], kezd[c], veg[c];



bool is_square(int a) {
    int gy=sqrt(a);
    return (gy*gy==a);
}



void solve(int x) {
	for(int i=x;;i++)
	{
		if(is_square(i))
		{
			int diff = i-x;
			solve(diff-1);
			for(int j=x;j>=diff;j--)
			{
				cout<<j<<" ";
			}
			break;
		}
	}
}
    
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        solve(n-1);
        cout << "\n";
    }
    return 0;
}
