#include<stdio.h>


void qsort(int *b, int *e)
{
	if(b==e || e-b==1)
	{
		return;
	}
	//pivot selection
	int pivInd = 0;
	int t = *b;
	*b = *(b+pivInd);
	*(b+pivInd) = t;
	int *i = b, *j = b+1;
	while(j!=e)
	{
		if(*j<=*b)
		{
			i++;
			int t = *i;
			*i = *j;
			*j = t;
		}
		j++;
	}
	t = *b;
	*b = *i;
	*i = t;
	qsort(b, i);
	qsort(i+1, e);
}

int main()
{
	int arr[] = {2, 3, 21, 1, 4, 56, 4, 2, 4, 5, 6,};
	int n = sizeof(arr)/sizeof(int);
	qsort(arr, arr+n);
	for(int i = 0;i<n;i++)
	{
		printf("%d%c", arr[i], (i==n-1)?'\n':' ');
	}
	return 0;
}

