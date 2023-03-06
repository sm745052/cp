#include<bits/stdc++.h>
using namespace std;

bool isprime(long long int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
		return false;
    return true;
}


int main()
{
	int n;
	cin>>n;
	long long int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		long long k = (long long)(sqrt(tmp));
		if(k*k==tmp && isprime(k))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
