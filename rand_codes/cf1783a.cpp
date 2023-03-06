#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    sort(arr.begin(), arr.end());
    if(arr[n-1]==arr[0]){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<arr[0]<<" "<<arr[n-1]<<" ";
        for(int i=1;i<n-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
