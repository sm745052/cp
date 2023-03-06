#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];


int subset_sum(int arr[], int n, int sum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
                t[i][j] = max(t[i-1][j-arr[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main(){
    int arr[] = {2, 1, 3};
    int sum = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subset_sum(arr, n, sum)<<endl;
}