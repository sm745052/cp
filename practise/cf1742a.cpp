#include<bits/stdc++.h>
using namespace std;
#define int long long int






void solve()
{
	int n, p, k;
	cin>>n;
	map<char, int> g1;
	map<char, int> g2;
	g1['a']++;
	g2['a']++;
	char mi1='a', ma2='a';
	for(int i=0;i<n;i++){
		cin>>p>>k;
		string st;
		cin>>st;
		if(p==1){
			for(int i=0;i<st.length();i++){
				if(st[i]==mi1){
					g1[mi1] += k;
				}
				else{
					if(st[i]<mi1){
						mi1 = st[i];
						g1[mi1] += k;
					}
				}
			}
		}
		if(p==2){
			for(int i=0;i<st.length();i++){
				if(st[i]==ma2){
					g2[ma2] += k;
				}
				else{
					if(st[i]>ma2){
						ma2 = st[i];
						g2[ma2] += k;
					}
				}
			}
		}
		if(ma2>mi1){
			cout<<"YES"<<endl;
		}
		else{
			if(ma2==mi1){
				if(g2[ma2]>g2[ma2]){
					cout<<"YES"<<endl;
				}
			}
		}
		cout<<"NO"<<endl;
	}
}



int32_t main()
{
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
	int t;cin>>t;while(t--)
	solve();
	return 0;
}