#include<bits/stdc++.h>
using namespace std;



map<pair<int,int>, int> store;

bool isPalendrome(string s, int i, int j)
{
	if(i==j)return true;
	if(j-i==1)return s[i]==s[j];
	if(store[make_pair(i, j)]==-1)
	{
		int tmp = isPalendrome(s, i+1, j-1);
		store[make_pair(i, j)] = tmp;
		return tmp && s[i]==s[j];
	}
	return store[make_pair(i, j)] && s[i]==s[j];
}





void solve(string s)
{
	int l = s.length();
	int dp[l][l];
	int max_l = 0;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
		{
			store[make_pair(i, j)] = -1;
		}
	}
	for(int i=0;i<l;i++)
	{
		for(int j=i;j<l;j++)
		{
			dp[i][j] = isPalendrome(s, i, j);
			if(dp[i][j])
			{
				max_l = max(max_l, j-i+1);
			}
		}
	}
	cout<<max_l<<endl;
}



int main()
{
	string s;
	cin>>s;
	solve(s);
	return 0;
}
