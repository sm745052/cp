#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int m;
	cin>>m;
	int B[m];
	for(int i=0;i<m;i++)
	{
		cin>>B[i];
	}
	if(*max_element(B, B+m) == *max_element(A, A+n))
	{
		cout<<"Alice\nBob"<<endl;
	}
	else if(*max_element(B, B+m) > *max_element(A, A+n))
	{
		cout<<"Bob\nBob"<<endl;
	}
	else
	{
		cout<<"Alice\nAlice"<<endl;
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
