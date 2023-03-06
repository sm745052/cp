#include <bits/stdc++.h>
using namespace std;
double t[5001][5001];


double prod(int n, int k, double arr[]){
    if(t[n][k]!=-1.0)return t[n][k];
    if(n==0 && k==0)return t[n][k]=1;
    if(k==0)return t[n][k]=1;
    if(n==0)return t[n][k]=0;
    if(n<k)return t[n][k]=0;
    return t[n][k]= arr[n-1]*prod(n-1, k-1, arr) + (1-arr[n-1]) * prod(n-1, k, arr);
}

int main()
{
    cout<< fixed << setprecision(10);
    for(int i=0;i<5001;i++){
        for(int j=0;j<5001;j++){
            t[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<prod(n, ceil((n+1)/2.0), arr)<<endl;
    return 0;
}