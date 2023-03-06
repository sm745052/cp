#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
			for (int i = 5; i * i <= n; i = i + 6)
				if (n % i == 0 || n % (i + 2) == 0)
					return false;
	return true;
}
int main()
{
	vector<int> prime_arr;
	for(int i=2;i<100000;i++)
	{
		if(is_prime(i))
		{
			prime_arr.push_back(i);
		}
	}
	int ls = 100000;
	while(true)
	{
		if(is_prime(ls))
		{
			prime_arr.push_back(ls);
			break;
		}
		ls++;
	}
	int n, m;
	cin>>n>>m;
	int arr[n][m];
	long sum_rows[m] = {0};
	long sum_cols[n] = {0};
	long min_r = LONG_MAX;
	long min_c = LONG_MAX;
	long mi;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int tmp;
			cin>>tmp;
			arr[i][j] = *lower_bound(prime_arr.begin(), prime_arr.end(), tmp) - tmp;
			sum_rows[j] += arr[i][j];
			sum_cols[i] += arr[i][j];
		}
	}
	min_r = *min_element(sum_cols, sum_cols+n);
	min_c = *min_element(sum_rows, sum_rows+m);
	cout<<min(min_r, min_c)<<endl;
	return 0;
}
