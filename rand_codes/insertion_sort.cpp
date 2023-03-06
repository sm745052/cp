#include<bits/stdc++.h>
using namespace std;

void sorted(int arr[], int n)
{
	for(int i=1;i<n;i++)
        {
                int key = arr[i];
                int j=i-1;
                while(j>=0 && arr[j]>key)
                {
                        arr[j+1] = arr[j];
                        j -=1;
                }
                arr[j+1] = key;
        }
        for(int i=0;i<n;i++)
        {
                cout<<arr[i]<<endl;
        }
}


int main()
{
	int n;
	cout<<"enter n: ";
	cin>>n;
	cout<<"enter array elements"<<endl;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sorted(arr, n);
	return 0;
}
