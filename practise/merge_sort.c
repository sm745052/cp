#include<stdio.h>






void print_array(int* b, int* e)
{
	while(b!=e)
	{
		printf("%d, ", *b);
		b++;
	}
	printf("\n");
}

/*
 * [2, 4, 3, 1, 2]
 *  0  1  2  3  4
 *  n=5
 *  mid=5/2=2
 *  sort([2, 4]) => [2, 4]
 *  sort([3, 1, 2]) => [1, 2, 3]
 *  merge([2, 4], [1, 2, 3]) Takes O(n) with more space else greater than O(n) time complexity in arrays. However, in linkedlists, O(n) can be 
 *  acheived without extra space, as it is easy to insert any node at any index in O(1).
 */


void merge_narr(int* b, int* m, int* e)
{
	//O(n) but space complexity is more
	int n_arr[e-b];
	int *p1 = b, *p2 = m;
	int ctr = 0;
	while(p1!=m && p2!=e)
	{
		if(*p1<(*p2))
		{
			n_arr[ctr] = *p1;
			ctr++;
			p1++;
		}
		else
		{
			n_arr[ctr] = *p2;
			ctr++;
			p2++;
		}

	}
	while(p1!=m)
	{
		n_arr[ctr] = *p1;
		p1++;
		ctr++;
	}
	while(p2!=e)
	{
		n_arr[ctr] = *p2;
		p2++;
		ctr++;
	}
	for(int i=0;i<e-b;i++)
	{
		b[i] = n_arr[i];
	}
}


void merge_samearray(int *b, int *m, int *e)
{
	//O(n^2)
	int *ptr = m;
	while(ptr!=e)
	{
		int key = *ptr;
		int *b_ptr = ptr-1;
		while(*b_ptr>key)
		{
			*(b_ptr+1) = *b_ptr;
			b_ptr--;
		}
		*(b_ptr+1) = key;
		ptr++;
	}
}



void sort(int *b, int *e)
{
	int n = e-b;
	if(n==1)
		return;
	int* mid = b + n/2;
	sort(b, mid);
	sort(mid, e);
//	merge_narr(b, mid, e);
	merge_samearray(b, mid, e);
}


int main()
{
	//printf("Hello\n");
	int arr[] = {1, 2, 1, 1,3 ,54, 65, 6, 4, 43, 3, 2, 3,4};
	int n = sizeof(arr)/sizeof(int);
	sort(arr, arr+n);
	print_array(arr,  arr+n);
	return 0;
}
