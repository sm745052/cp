#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	vector<char> g(n);
    int l=0, r=0;
    int flag = 0;
    int f_l=-34;
    int ctr=1;
    for(auto &i:g){
        cin>>i;
        // cout<<i<<endl;
        if(i=='R')r++;
        else{
            if(r>0)flag=1;
            l++;
            if(l==1){
                f_l = ctr;
                // cout<<"hello"<<f_l;
            }
        }
        ctr++;
    }
    if(flag){
        cout<<0<<endl;
    }
    else{
        if(l==0 || r==0){
            cout<<-1<<endl;
        }
        else{
            cout<<f_l<<endl;
        }
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
