#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long b)     //O(log n)
{
	if(b==0)return 1;
	long long tmp = power(a, b/2); // A^B = A^(B/2) * A^(B/2)
	tmp *= tmp;
	if(b%2==1)  //if B was odd then 0.5 was lost during integral division each time in B/2 for 2 times
	{
		tmp *= a;
	}
	return tmp;
}



int main()
{
	cout<<power(2, 30)<<endl;
	return 0;
}
