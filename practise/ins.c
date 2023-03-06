#include<stdlib.h>
#include<stdio.h>


void insertion_sort(int *b, int *e){
	int n = e-b;
	for(int i=1;i<n;i++){
		int key = b[i];
		int j=i-1;
		while(j>=0 && b[j]>key){
			b[j+1] = b[j];
			j--;
		}
		b[j+1] = key;
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}
	insertion_sort(arr, arr+n);
	for(int j=0;j<n;j++){
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}
