#include<bits/stdc++.h>
using namespace std;



int check(long long k, int* arr, int n){
	//check if array can be broken into segments of equal sums and return the thickness
	long long ps = 0;
	int t = -1;
	int pt = 0;
	for(int i=0;i<n;i++){
		ps+=arr[i];
		pt++;
		// cout<<"ps = "<<ps<<endl;
		if(ps>k)break;
		if(ps == k){

			if(i==n-1)break;
			ps = 0;
			t = max(pt, t);
			// cout<<t<<endl;
			pt = 0;
		}
	}

	if(ps!=k){
		// cout<<"sdch "<<ps<<endl;
		return -1;
	}
	// cout<<"ps = "<<t<<endl;
	return max(pt, t);
}






void solve()
{
	int n;
	cin>>n;
	long long sum = 0;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	vector<int> divisors;
	for(int i=1;i<=sqrt(sum);i++){
		if(sum%i == 0){
			divisors.push_back(i);
			if(i!=sum/i)divisors.push_back(sum/i);
		}
	}

	int t = 2002;
	sort(divisors.begin(), divisors.end());
	for(auto &i:divisors){
		// cout<<"checking for sum = "<<i<<endl;
		int kk = (check(i, arr, n));
		if(kk!=-1){
			t = min(kk, t);
		}
	}
	cout<<t<<endl;
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