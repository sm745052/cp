#include<stdio.h>


int ksmallest(int *b, int *e, int k)
{
	if(e-b==0)
	{
		return 1e8;
	}
	if(e-b==1)
	{
		return *b;
	}
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
	int t = *b;
	*b = *i;
	*i = t;
	if(i-b==k-1)
	{
		return *i;
	}
	if(i-b<k-1)
	{
		return ksmallest(i+1, e, k - (i-b+1));
	}
	return ksmallest(b, i-1, k);
}

int main()
{
	int arr[] = {1, 2, 3, 21, 13, 20};
	int n = sizeof(arr)/sizeof(int);
	int k = 6;
	int v = ksmallest(arr, arr+n, n-k+1);
	for(int i = 0;i<n;i++)
	{
		printf("%d%c", arr[i], (i==n-1)?'\n':' ');
	}
	printf("val = %d\n", v);
	return 0;
}

