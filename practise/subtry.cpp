#include<bits/stdc++.h>
using namespace std;


int hash1(int x,int y){
	return 2002*x + y;
}

void solve()
{
	int n;
	cin>>n;
	set<int> s;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		int a, b;
		cin>>a>>b;
		v.push_back({a, b});
		s.insert(hash1(a,b));
	}
	sort(v.begin(), v.end());
	int ctr = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int A = v[i].first + v[j].first;
			int B = v[i].second + v[j].second;
			if(A&1 || B&1){
				continue;
			}
			A/=2;
			B/=2;
			if(s.find(hash1(A,B))!=s.end()){
				ctr++;
			}
		}
	}
	cout<<ctr<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
	// int t;cin>>t;while(t--)
	solve();
	return 0;
}