#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, L;
	cin>>N>>L;
	int a[N];
	int fs = L/2;
	int sp = 0, dp=0; 
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int i=0;i<N;i++){
		if(a[i]==2 && L-2*sp-3*dp<2){
			cout<<"No"<<endl;return 0;
		}
		if(a[i]-1)dp+=1;
		else sp+=1;
	}
	cout<<"Yes"<<endl;
	return 0;
}
