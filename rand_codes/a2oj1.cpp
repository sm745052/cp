#include <bits/stdc++.h>
using namespace std;
int main() {
    
	int N,K,D;
	cin>>N>>K>>D;
	
	vector<int> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
    
    long long dp[N+1][K+1][D];
	memset(dp, -1, sizeof(dp));


	dp[0][0][0] = 0;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<K+1;j++){
			for(int k=0;k<D;k++){
				if(dp[i-1][j][k]==-1)continue;
				
				// transition when a_i isn't chosen
				dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
				
				// transition when a_i is chosen
				if(j!=K){
					dp[i][j+1][(k+a[i-1])%D] = max(dp[i][j+1][(k+a[i-1])%D],dp[i-1][j][k] + a[i-1]);
				}
			}
		}
	}
	
	cout<<dp[N][K][0]<<endl;
	
	return 0;
}