#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int dp[n][n];   //dp[i][j] -> reaching j using i steps
	//max no of steps can be when k=1 and everything else is consecutively increasing => 1st step is 1 length, 2nd step is 2 length and so on.
	//this means max no of steps can me of order sqrt(n)
	//okay
}
