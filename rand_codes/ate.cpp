#include<bits/stdc++.h>
using namespace std;
#define int long long






signed main(){
    int h, w;
    cin>>h>>w;
    int arr[h][w];
    int vis[h][w];
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }


    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j>0 && arr[i][j-1]==arr[i][j]){
                vis[i][j] = 1;
            }
            if(j+1<w && arr[i][j+1]==arr[i][j]){
                vis[i][j] = 1;
            }
        }
    }
    int cnt = 0;


    int nof = 0;
    for(int i=1;i<h;i++){
        int flag1 = 0, flag2=0;
        for(int j=0;j<w;j++){
            if(vis[i-1][j]!=1 && arr[i][j]!=arr[i-1][j]){
                flag1=1;
                vis[i-1][j]=1;
                vis[i][j]=1;
            }
            if(vis[i-1][j]!=1 && arr[i][j]==arr[i-1][j]){
                flag2=1;
                vis[i-1][j]=1;
                vis[i][j]=1;
            }
        }
        if(flag1&flag2){
            cout<<-1<<endl;
            return 0;
        }
        else if (!(flag1|flag2)) {
            cnt += min(nof, i-nof);
            nof = 0;
        }


        if(flag1){
            nof++;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}