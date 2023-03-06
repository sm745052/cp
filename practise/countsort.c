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
	int C[m+1]={0};
	for(int i=0;i<n;i++){
		C[A[i]] = C[A[i]] + 1;
	}
	for(int i=2;i<=m;i++){
		C[i] = C[i] + C[i-1];
	}
	for(int j=n-1;j>=0;j--){
		B[C[A[j]]-1] = A[j];
		C[A[j]]=C[A[j]]-1;
	}
	for(int i=0;i<n;i++){
		print("%d ", B[i]);
	}
	print("\n");
	return 0;
}