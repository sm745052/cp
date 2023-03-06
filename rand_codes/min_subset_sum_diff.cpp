#include<bits/stdc++.h>
using namespace std;


int no_of_subset_sum(int arr[], int n, int s){
    if(s==0)return 1;
    if(n==0)return 0;
    return no_of_subset_sum(arr, n-1, s) + no_of_subset_sum(arr, n-1, s-arr[n-1]);
}



int main(){
    int arr[] = {3, 2, 5, 3, 2, 1, 4, 9,6, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ts =0;
    ts = accumulate(arr, arr+n, ts);
    for(int ps=0;ps<=ts/2+1;ps++){
        int k = no_of_subset_sum(arr, n, ps);
        if(k>0){
            cout<<k<<endl;
        }
    }
    cout<<endl;
    return 0;
}