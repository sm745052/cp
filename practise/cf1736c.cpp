#include<bits/stdc++.h>
using namespace std;

int dp[200000][2];


int C(int n, int r)
{
       if(n==r) return dp[n][r] = 1; //Base Case
       if(r==0) return dp[n][r] = 1; //Base Case
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
       return dp[n][r] = C(n-1,r) + C(n-1,r-1);
}




void solve()
{
	int n;
	cin>>n;
	int arr[n];
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int t = 0;t<n;t++){
		int tr = t;
		int tr1;
		// cout<<"hello1"<<endl;
		do{
			tr++;
		}while(tr<n && arr[tr]<tr-tr+1);
		// cout<<"hello2"<<endl;
		tr--;
		// cout<<"tr="<<tr<<endl;
		tr1 = tr;
		do{
			tr1++;
		}while(tr1<n && arr[tr1]>=tr1-tr+1);
		// cout<<"tr1="<<tr1<<endl;
		// cout<<"hello3"<<endl;
		tr1--;

		int l = tr1-tr;
		ans += l;
	}
	cout<<ans+n<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
	int t;cin>>t;while(t--)
	solve();
	return 0;
}