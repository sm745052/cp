#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    int i=0;
    int ctr=0;
    int k=0;
    while(true){
        if(a[i]==k+1){
            i++;
            continue;
        }
        ctr++;
        k++;
        sort(a.begin()+i, a.begin()+i+min(m, n-i));
        if(a[i]==k+1){
            i++;
            k++;
        }
        for(;i<min(i+m, n-i);i++)
            a.push_back(a[i]);
            cout<<a[i];
        if(i==n)break;
    }
    cout<<ctr<<endl;
    a.clear();
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
