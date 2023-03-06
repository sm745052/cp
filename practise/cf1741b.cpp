#include<bits/stdc++.h>
using namespace std;

// int dp[200000][2];


// int C(int n, int r)
// {
//        if(n==r) return dp[n][r] = 1; //Base Case
//        if(r==0) return dp[n][r] = 1; //Base Case
//        if(r==1) return dp[n][r] = n;
//        if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
//        return dp[n][r] = C(n-1,r) + C(n-1,r-1);
// }








int check(int t, int* arr, int* sums, int n){
	// cout<<"checking "<<t<<endl;
	// cout<<"hello"<<endl;
	for(int i=0;i<=n;i++){
		int s = sums[i+t+1]-sums[i];
		int k =0;
		int ps = 0;
		while(k<i){
			int tmpk = k;
			int kt = 0;
			// cout<<"hello"<<endl;
			while(k+kt<i){
				if(sums[k+kt+1] - sums[k]==s){
					k += kt;
					// cout<<"hello"<<endl;
					break;
				}
				if(sums[k+kt+1] - sums[k]>s){
					return 0;
				}
				kt++;
				// cout<<"hello"<<endl;
			}
			// cout<<"hello"<<endl;
			if(k+kt>=i)break;
		}
		cout<<"prevpass"<<endl;
		k =i+t;
		ps = 0;
		// cout<<"hello"<<endl;
		while(k<n){
			// cout<<"hello"<<endl;
			int tmpk = k;
			int kt = 0;
			while(k+kt<n){
				if(sums[k+kt+1] - sums[k]==s){
					k += kt;
					break;
				}
				if(sums[k+kt+1] - sums[k]>s){
					return 0;
				}
				kt++;
			}
			if(k+kt>=n)break;
			// k+=kt;
		}
		return 1;
	}
	return 0;
}



void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int lo = 1;
	int hi = 2*n;
	int ans = -1;
	int sums[n+1]={0};
	for(int i=1;i<=n;i++){
		sums[i] = arr[i-1]+sums[i-1];
	}
	while(lo<=hi){
		int mid = (lo+hi)/2;
		// cout<<"checked "<<check(mid, arr, sums, n)<<endl;
		if(check(mid, arr, sums, n)){
			hi = mid-1;
			ans = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout<<ans<<endl;
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