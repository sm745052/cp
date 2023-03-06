#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, d;
    cin>>n>>k>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n+1][k+1][d];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int t=0;t<d;t++){
                int ner = (a[i-1]%d +t)%d;
                if(dp[i-1][j-1][t]!=-1)
                    dp[i][j][ner] = max(dp[i-1][j-1][t] + a[i-1], dp[i-1][j][ner]);
                else
                    dp[i][j][ner] = dp[i-1][j][ner];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int t=0;t<d;t++){
                cout<<dp[i][j][t]<<" ";
            }
            cout<<"     ";
        }
        cout<<endl;
    }
    cout<<dp[n][k][0]<<endl;
    return 0;
}