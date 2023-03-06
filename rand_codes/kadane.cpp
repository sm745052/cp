#include<bits/stdc++.h>
using namespace std;

int ans(int arr[], int n){
    if(n==0)return INT_MIN;
    return max(ans(arr, n-1)+arr[n-1], arr[n-1]);
}


int main(){
    int arr[] = {1, -2, 3, 4, -5, 3, -2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<ans(arr, n)<<endl;
    return 0;
}