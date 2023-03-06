#include<bits/stdc++.h>
using namespace std;

int t[10001][10001];



int count_subset_sum(int arr[], int n, int s){
    if(t[n][s]!=-1)return t[n][s];
    if(s==0)return t[n][s]=1;
    if(n==0)return t[n][s]=0;
    if(arr[n-1]<=s){
        return t[n][s]=count_subset_sum(arr, n-1, s) + count_subset_sum(arr, n-1, s-arr[n-1]);
    }
    return t[n][s]=count_subset_sum(arr, n-1, s);
}



int count_subset_given_diff(int arr[], int n, int diff){
    memset(t, -1, sizeof(t));
    int arr_sum = 0;
    arr_sum = accumulate(arr, arr+n, arr_sum);
    if((arr_sum+diff)%2!=0)return 0;      //bcoz on dividing by 2, if not divisible, sum of the subset has to be float i.e. not possible since all elements are int, however this condition is necessary else c++ may round the answer to next lower int digit which is wrong
    int s = (arr_sum+diff)/2;
    return count_subset_sum(arr, n, s);
}


int main(){
    int arr[] = {1, 1, 2, 3, 5, 6, 7, 8, 9};
    int diff = 2;
    cout<<count_subset_given_diff(arr, sizeof(arr)/sizeof(arr[0]), diff)<<endl;
    return 0;
}