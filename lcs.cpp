#include<bits/stdc++.h>
using namespace std;


int lcs(string str1, string str2, int a, int b)
{
	if(a==str1.size() || b == str2.size())
	{
		return 0;
	}
	else if(str1[a] == str2[b])
	{
		return 1+lcs(str1, str2, a+1, b+1);
	}
	return max(lcs(str1, str2, a, b+1), lcs(str1, str2, a+1, b));
}

int main()
{
	string str1, str2;
	cin>>str1>>str2;
	int l1 = str1.size(), l2 = str2.size();
	cout<<lcs(str1, str2, 0, 0)<<endl;
	return 0;
}
