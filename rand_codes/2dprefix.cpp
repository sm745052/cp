#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j] = 1;
        }
    }
    cout<<arr[0][0]<<endl;
    int parr[5][5];
    parr[0][0] = arr[0][0];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0 && j==0)continue;
            if(i==0){
                parr[i][j] = parr[i][j-1] + arr[i][j];
            }
            else if(j==0){
                parr[i][j] = parr[i-1][j] + arr[i][j];
            }
            else{
                parr[i][j] = arr[i][j] + parr[i][j-1] + parr[i-1][j] - parr[i-1][j-1];
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<parr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}