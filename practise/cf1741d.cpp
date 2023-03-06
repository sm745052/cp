#include<bits/stdc++.h>
using namespace std;

int steps;

void mysort(int arr[], int i, int j){
	if(steps==-1)return;
	int n = j-i;
	if(n==1)return;
	if(n==0)return;
	int max1=INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
	for(int k=i;k<i+n/2;k++){

		max1 = max(arr[k],max1);
		min1 = min(arr[k],min1);
	}
	for(int k=i+n/2;k<i+n;k++){
		max2 = max(arr[k],max2);
		min2 = min(arr[k],min2);
	}
	if(max1<min2){
		steps+=0;
	}
	else if(min1>max2){
		steps+=1;
	}
	else{
		steps=-1;
		return;
	}
	mysort(arr, i, i+n/2);
	mysort(arr, i+n/2, i+n);
}

void solve()
{
	steps = 0;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mysort(arr, 0, n);
	cout<<steps<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
	int t;cin>>t;while(t--)
	solve();
	return 0;
}