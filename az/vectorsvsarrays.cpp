#include<bits/stdc++.h>
using namespace std;
/*
 * keypoints to note
 * int arr[] = int* arr in function argument
 * treat vector as a object => ptr of vector doesnot correspond to the first element but to the whole vector
*/

void print(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}




void print(vector<int>* ptr)
{
	for(int i=0;i<ptr->size();i++)
	{
		cout<<(*ptr)[i]<<" ";
	}
	cout<<endl;
}


/*
 *
 * overload resolution fails here int arr[] and int* arr are identical in function parameter
 *
 *
void print(int arr[], int n)
{
        for(int i=0;i<n;i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
}
*/



void print(int* arr, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}



int main()
{
	int arr[3] = {1, 2, 3};
	vector<int> vec = {1, 2, 3};
	print(arr, 3);
	print(vec);
	print(&vec);
	return 0;
}
