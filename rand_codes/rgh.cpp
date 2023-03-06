#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int t[105][100005];


void solve()
{
	memset(t, -1, sizeof(t));
	int n;
	cin>>n;
	vector<int> a(n);
	int s = 0;
	for(auto &i:a)cin>>i, s+=i;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0)t[i][j]=1;
			else if(i==0)t[i][j]=0;
			else{
				t[i][j] = t[i-1][j];
				if(j-a[i-1]>=0)
					t[i][j] = t[i][j] | t[i-1][j-a[i-1]];
			}
		}
	}
	set<int> ss;
	for(int j=1;j<=s;j++){
		if(t[n][j]){
			ss.insert(j);
		}
	}
	cout<<ss.size()<<endl;
	for(auto i:ss)cout<<i<<" ";
	cout<<endl;
}



int32_t main()
{
    int tr=1;
    for(int i=0;i<tr;i++)
    {
        solve();
    }
    return 0;
}
