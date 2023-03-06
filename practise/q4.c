#include<stdio.h>

void sort(int *b, int *e)
{
	int* h = b;
	b++;
	while(b!=e)
	{
		if((b-h)%2==0)
		{
			if(*b > *(b-1))
			{
				int t = *b;
				*b = *(b-1);
				*(b-1) = t;
			}
		}
		else
		{
			if(*b < *(b-1))
			{
				int t = *b;
                                *b = *(b-1);
                                *(b-1) = t;
			}
		}
		b++;
	}
}


int main()
{
	int n;
	printf("Enter n:");
	scanf("%d", &n);

	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", arr+i);
	}

	sort(arr, arr+n);
	for(int i=0;i<n;i++)
	{
		printf("%d%c", arr[i], (i!=n-1?' ':'\n'));
	}
	return 0;
}
