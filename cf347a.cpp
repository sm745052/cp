#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int ma = -10000;
	int mi = 10000;
	int pma = -1;
	int pmi = -1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(ma<arr[i])
		{
			ma = arr[i];
			pma = i;
		}
		if(mi>arr[i])
		{
			mi = arr[i];
			pmi = i;
		}
	}
	int sum = ma-mi;
	int tmp = arr[0];
	arr[0] = arr[pma];
	arr[pma] = tmp;
	ma = -100000;
	mi = 100000;
	pma = -1;
	pmi = -1;
	for(int i=0;i<n;i++)
        {
                if(ma<arr[i])
                {
                        ma = arr[i];
                        pma = i;
                }
                if(mi>arr[i])
                {
                        mi = arr[i];
                        pmi = i;
                }
        }
	tmp = arr[n-1];
	arr[n-1] = arr[pmi];
	arr[pmi] = tmp;
	sort(arr+1, arr+(n-1));
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	return 0;
}
