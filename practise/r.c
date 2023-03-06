#include<stdlib.h>
#include<stdio.h>


int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	int B[n];
	int m = -1;
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
		if(arr[i]>m)m=arr[i];
	}
	int C[m+1];
	for(int i=0;i<=m;i++){
		C[i] = 0;
	}
	for(int i=0;i<n;i++){
		C[arr[i]] = C[arr[i]] + 1;
	}
	for(int i=2;i<=m;i++){
		C[i] = C[i] + C[i-1];
	}
	for(int j=n-1;j>=0;j--){
		B[C[arr[j]]-1] = arr[j];
		C[arr[j]]=C[arr[j]]-1;
	}
	for(int i=0;i<n;i++){
		printf("%d ", B[i]);
	}
	printf("\n");
	return 0;
}
