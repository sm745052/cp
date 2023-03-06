#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    set<int> s1, s2;
    for(int i=1;i<=n;i++){
        s1.insert(-i);
        s2.insert(-i);
    }
    vector<int> ar1(n, -1), ar2(n, -1);
    for(int i=0;i<n;i++){
        if(s1.find(-a[i])!=s1.end()){
            s1.erase(s1.find(-a[i]));
            ar1[i] = a[i];
        }
        else{
            if(s2.find(-a[i])!=s2.end()){
                s2.erase(s2.find(-a[i]));
                ar2[i] = a[i];
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ar1[i]==-1){
            if(s1.upper_bound(-ar2[i])!=s1.end()){
                    ar1[i] = - (*(s1.upper_bound(-ar2[i])));
                    s1.erase((s1.upper_bound(-ar2[i])));
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        if(ar2[i]==-1){
            if(s2.lower_bound(-ar1[i])!=s2.end()){
                ar2[i] = - (*(s2.lower_bound(-ar1[i])));
                s2.erase((s2.lower_bound(-ar1[i])));
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto i:ar1)cout<<i<<" ";
    cout<<endl;
    for(auto i:ar2)cout<<i<<" ";
    cout<<endl;
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
