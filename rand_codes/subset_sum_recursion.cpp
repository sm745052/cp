#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];


int subset_sum(int arr[], int n, int sum){
    if(n==0){
        if(sum==0)return t[n][sum]=1;
        return t[n][sum]=0;
    }
    if(sum==0)return t[n][sum]=1;
    if(t[n][sum]!=-1)return t[n][sum];
    return t[n][sum]=max(subset_sum(arr, n-1, sum-arr[n-1]), subset_sum(arr, n-1, sum));
}

int main(){
    memset(t, -1, sizeof(t));
    int arr[] = {2, 1, 3};
    int sum = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subset_sum(arr, n, sum)<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}