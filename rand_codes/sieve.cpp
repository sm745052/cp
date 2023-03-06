#include<bits/stdc++.h>
using namespace std;

void sieve(int n){
	bool nprime[n+1]={0};
	for(int p=2;p*p<=n;p++){
		if(nprime[p]==0){
			for(int i=p*p;i<=n;i+=p){
				nprime[i] = 1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(nprime[i]==0)cout<<i<<endl;
	}
}


int main(){
	int n;
	cin>>n;
	sieve(n);
	return 0;
}
