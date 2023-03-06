#include<bits/stdc++.h>
using namespace std;
int main()
{
	//gives the nth_element(arr, arr+k, arr+n) sorts the array in such a way that now the kth item(k-1 index) will be the same to the kth element in a sorted array but the time complexity is O(n)
	int arr[] = { 3, 2, 10, 45, 33, 56, 23, 47, 60 };
	//sort(arr, arr+5);
	nth_element(arr, arr+3, arr+9);
	for(int i=0;i<sizeof(arr) / sizeof(*arr);i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
