#include<stdio.h>
#include<stdlib.h>


void max_heapify(int *arr, int n, int i){
	int t;
	if(i>n/2)return;
	if(2*i+1>n){
		if(arr[2*i]>arr[i]){
			t = arr[i];
			arr[i] = arr[2*i];
			arr[2*i] = t;
		}
	}
	else{
		if(arr[2*i]>arr[i]){
                        t = arr[i];
                        arr[i] = arr[2*i];
                        arr[2*i] = t;
                }
		if(arr[2*i+1]>arr[i]){
                        t = arr[i];
                        arr[i] = arr[2*i+1];
                        arr[2*i+1] = t;
                }
		max_heapify(arr, n, 2*i);
		max_heapify(arr, n, 2*i+1);
	}
}



int main(){
	int arr[] = {0, 2, 1, 3, 4, 56, 4, 3, 4, 5, 5,6 ,6, 7, 8 , 7, 6};
	int n = sizeof(arr)/sizeof(arr[0])-1;
	max_heapify(arr, n, 1);
	for(int j=n/2;j>=1;j--){
		max_heapify(arr, n, j);
	}
	printf("Size of array = %d\n", n);
	for(int i=0;i<n;i++)
	{
		printf("%d%c", arr[i], (i!=n-1)?' ':'\n');
	}
	return 0;
}
