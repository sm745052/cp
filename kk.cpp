#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >t(10000, vector<int> (10000, -1));
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    if(t[n][k] != -1)return t[n][k];
    if(k==0)return t[n][k] = 1;
    if(n==0)return t[n][k] = 0;
    if(arr[n-1]<=k)return t[n][k] = max(subsetSumToK(n-1, k-arr[n-1], arr), subsetSumToK(n-1, k, arr));
    return t[n][k] = subsetSumToK(n-1, k, arr);
}
int main(){
	return 0;
}
