#include<bits/stdc++.h>
using namespace std;

int no_of_subset_sum(int arr[], int n, int s){
    if(s==0)return 1;
    if(n==0)return 0;
    return no_of_subset_sum(arr, n-1, s) + no_of_subset_sum(arr, n-1, s-arr[n-1]);
}


int main(){
    int arr[]={1,2,3, 3, 2, 1, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s = 3;
    cout<<no_of_subset_sum(arr, n, s)<<endl;
    return 0;
}