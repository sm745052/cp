#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int>g(n*n, 0);
    g[0]=1;
    int d = n*n-1;
    for(int i=1;i<n*n;i++){
        g[i] = d+g[i-1];
        if(d<0)d = -(d+1);
        else
            d = -(d-1);
    }
    int ctr=0;
    int r=0;
    vector<vector<int>>arr(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        if(r%2==0){
            for(int j=0;j<n;j++){
                arr[i][j] = g[ctr];
                ctr++;
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                arr[i][j] = g[ctr];
                ctr++;
            }
        }
        r++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
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
