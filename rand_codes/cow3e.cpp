#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m, u, q;
	cin>>n>>m>>u>>q;
	int arr[n][m];
	int parr[n][m];
	int q_arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			q_arr[i][j] = 0;
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<u;i++){
		int k, r1, c1, r2, c2;
		cin>>k>>r1>>c1>>r2>>c2;
		q_arr[r1][c1] += k;
		if(c2+1<m)
		q_arr[r1][c2+1] += -k;
		if(r2+1<n)
		q_arr[r2+1][c1] += -k;
		if(c2+1<m && r2+1<n)
		q_arr[r2+1][c2+1] += k;
	}
	for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
			if(i==0&&j==0)continue;
                        if(i==0)q_arr[i][j]=q_arr[i][j-1]+q_arr[i][j];
                        else if(j==0)q_arr[i][j]=q_arr[i-1][j]+q_arr[i][j];
                        else q_arr[i][j]=q_arr[i][j]+q_arr[i][j-1]+q_arr[i-1][j]-q_arr[i-1][j-1];
                }
        }
	for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        arr[i][j] += q_arr[i][j];
                }
        }
	for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        if(i==0 && j==0)parr[i][j]=arr[i][j];
                        else if(i==0)parr[i][j]=parr[i][j-1]+arr[i][j];
                        else if(j==0)parr[i][j]=parr[i-1][j]+arr[i][j];
                        else parr[i][j]=arr[i][j]+parr[i][j-1]+parr[i-1][j]-parr[i-1][j-1];
                }
        }
	for(int i=0;i<q;i++){
		int r1, c1, r2, c2;
		cin>>r1>>c1>>r2>>c2;
		int ans = parr[r2][c2];
		if(r1>0)ans-=parr[r1-1][c2];
		if(c1>0)ans-=parr[r2][c1-1];
		if(r1>0 && c1>0)ans+=parr[r1-1][c1-1];
		cout<<ans<<endl;
	}
	return 0;
}
