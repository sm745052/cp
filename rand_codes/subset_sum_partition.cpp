#include<bits/stdc++.h>
using namespace std;

int subset_sum(int arr[], int n, int s){
    if(s==0)return 1;
    if(n==0)return 0;
    return max(subset_sum(arr, n-1, s), subset_sum(arr, n-1, s-arr[n-1]));
}


int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s = 0;
    s = accumulate(arr, arr+n, s);
    if(s%2!=0)
        cout<<0<<endl;
    else
        cout<<subset_sum(arr, n, s/2)<<endl;
    return 0;
}