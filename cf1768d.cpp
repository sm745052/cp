#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
        i--;
    }
    vector<int> cl(n, -1);
    int v=0;
    for(int i=0;i<n;i++){
        if(cl[i]==-1)v++;
        int tr = i;
        while(cl[tr]==-1){
            cl[tr]=v;
            tr = arr[tr];
        }
    }
    int m = INT_MAX;
    for(int i=0;i<n-1;i++){
        if(cl[i]!=cl[i+1]){
            m = min(n-(v-1), m);
        }
        else{
            m = min(n-(v+1), m);
        }
    }
    cout<<m<<endl;
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
