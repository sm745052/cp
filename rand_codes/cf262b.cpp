#include<bits/stdc++.h>
using namespace std;
int pop_front(std::vector<int>& vec)
{
	if(vec.empty())return 0;
	int a = vec[0];
	vec.erase(vec.begin());
	return a;
}
int sum(std::vector<int>& v)
{
	if(v.empty())return 0;
	int s = 0;
	s = accumulate(v.begin(), v.end(), 0);
	return s;
}
int main()
{
	int n, k;
	cin>>n>>k;
	int s = 0;
	int ctr = k;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		arr.push_back(c);
	}
	while(arr.size()>0 && arr[0]<0 && k>0)
	{
		k--;
		s += abs(pop_front(arr));
	}
	if(arr[0]==0 || (k>=0 && k%2==0))
	{
		s += sum(arr);
		cout<<s<<endl;
		return 0;
	}
	if(k>0)
		s += -1 * pop_front(arr);
	s += sum(arr);
	cout<<s<<endl;
	return 0;
}
