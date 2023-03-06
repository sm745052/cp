#include<stdlib.h>
#include<stdio.h>




int* partition(int *b, int *e){
	int n = e-b;
	int j=0;
	for(int i=1;i<n;i++){
		if(b[i]<=b[0]){
			j++;
			int tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
		}
	}
	int tmp = b[0];
	b[0] = b[j];
	b[j] = tmp;
	return b+j;
}





void qs(int *b, int* e){
	int n = e-b;
	if(n<2)return;
	int* k = partition(b, e);
	qs(b, k);
	qs(k+1, e);
}



int main(){
	int arr[5] = {4, 51, 62, 4, 3};
	qs(arr, arr+5);
	for(int i=0;i<5;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
