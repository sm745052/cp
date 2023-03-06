#include<stdio.h>

void MAX_HEAPIFY(int* b, int* e, int i)
{
	int n = e-b;
	int t;
	if(i>n/2)return;
	if(2*i+1>=n)
	{
		i-=1;
		if((*(b+2*i-1))>(*(b+i)))
		{
			t = *(b+2*i-1);
			*(b+2*i-1) = *(b+i);
			*(b+i) = t;
		}
	}
	else
	{
		i-=1;
		if((*(b+2*i-1))>(*(b+i)))
                {
                        t = *(b+2*i-1);
                        *(b+2*i-1) = *(b+i);
                        *(b+i) = t;
                }
		if((*(b+2*i+1))>(*(b+i)))
                {
                        t = *(b+2*i+1);
                        *(b+2*i+1) = *(b+i);
                        *(b+i) = t;
                }
		MAX_HEAPIFY(b, e, 2*i-1);
		MAX_HEAPIFY(b, e, 2*i+1);
	}
}
int main()
{
	int arr[] = {2, 1, 3, 4, 56, 4, 3, 4, 5, 5,6 ,6, 7, 8 , 7, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	MAX_HEAPIFY(arr, arr+n, n/2);
	printf("Size of array = %d\n", n);
	for(int i=0;i<n;i++)
	{
		printf("%d%c", arr[i], (i!=n-1)?' ':'\n');
	}
	return 0;
}
