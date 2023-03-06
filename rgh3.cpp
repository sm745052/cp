#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	for(int i=1;i<n;i++){
		int j;
		for(j=i;j<n;j+=i){
			if(s[j]==s[j-i])break;
		}
		cout<<j+1<<endl;
	}
	return 0;
}
