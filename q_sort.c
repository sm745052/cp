#include<stdio.h>


void q_sort(int* b, int* e)
{
	if(e-b==1 || b==e)
	{
		return;
	}
	int pivot = *b;
	int *i, *j;
	i=b;
	j=b+1;
	while(j!=e)
	{
		if(*j<pivot)
		{
			i++;
			int t = *j;
			*j = *i;
			*i = t;
		}
		j++;
	}
	int t = *b;
	*b = *i;
	*i = t;
	q_sort(b, i);
	q_sort(i+1, e);
}



int main()
{
	int arr[] = {4, 2, 3, 45, 234, 45, 234, 23, 12, 4,5 ,67 , 89};
	int n = sizeof(arr)/sizeof(int);
	q_sort(arr, arr+n);
	for(int i=0; i<n; i++)
	{
		printf("%d%c", arr[i], (i==n-1)?'\n':' ');
	}
	return 0;
}
