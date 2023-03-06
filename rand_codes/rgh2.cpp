#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long


void solve()
{
        string s1 = "slaifhladbvciudbluudbvliaebviablbvfiluaerfiasbcilbclvliabv", s2 = "jsjcvjhavckjgdvckjsdv cjvcljh cljsadvcjhvjcvjhdvcjhvcjkadsvj,sacvhksdav";
        int m=s1.length(), n=s2.length();
 	int dp[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				dp[i][j]=0;
				continue;
			}
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
        int i=m, j=n;
        string res="";
        while(i>0 && j>0){
                if(s1[i-1]!=s2[j-1]){
                        if(dp[i-1][j]>dp[i][j-1]){
                                i--;
                        }
                        else{
                                j--;
                        }
                }
                else{
                        res.push_back(s1[i-1]);
                        i--;
                        j--;
                }
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
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
