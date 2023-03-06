#include<bits/stdc++.h>
using namespace std;

int dp[200000][2];


// int C(int n, int r)
// {
//        if(n==r) return dp[n][r] = 1; //Base Case
//        if(r==0) return dp[n][r] = 1; //Base Case
//        if(r==1) return dp[n][r] = n;
//        if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
//        return dp[n][r] = C(n-1,r) + C(n-1,r-1);
// }




void solve()
{
	string a, b;
	cin>>a>>b;
	// cout<<a<<" "<<b<<"--";
	if(a[a.length()-1]<b[b.length()-1]){
		cout<<">"<<endl;
	}
	else if(a[a.length()-1]>b[b.length()-1]){
		cout<<"<"<<endl;
	}
	else{
		if(a.length()<b.length()){
			cout<<((a[a.length()-1]=='S')?">":"<")<<endl;
		}
		else if(a.length()>b.length()){
			cout<<((a[a.length()-1]=='S')?"<":">")<<endl;
		}
		else{
			cout<<'='<<endl;
		}
	}
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