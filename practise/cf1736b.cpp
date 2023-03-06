#include<bits/stdc++.h>
using namespace std;

pair<map<int,int>, set<int>> primeFactors(int n)
{
	map<int, int> g1;set<int> g2;;
    while (n % 2 == 0)
    {
    	g1[2]++;
    	g2.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            g1[i]++;
            g2.insert(i);
            n = n/i;
        }
    }
    if (n > 2){
        g1[n]++;
        g2.insert(n);
    }
    return make_pair(g1, g2);
}






void solve()
{
	int n;
	int ans = 0;
	cin>>n;
	int a[n];
	vector<map<int, int> > factors;
	set<int> all_factors;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pair<map<int,int>, set<int> > k = primeFactors(a[i]);
		cout<<a[i]<<"factors = "<<endl;
		factors.push_back(k.first);
		for(auto &i:k.first){
			cout<<i.first<<"--"<<i.second<<endl;
		}
		all_factors.insert(k.second.begin(), k.second.end());
	}
	for(auto &i:all_factors){
		for(int j=1;j<n;j++){
			if(factors[j][i]>factors[j-1][i]){
				cout<<"NO"<<endl;return;
			}
		}
	}
	cout<<"YES"<<endl;
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