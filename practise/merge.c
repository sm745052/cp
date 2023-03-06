#include<stdlib.h>
#include<stdio.h>


void ms(int *b, int *e){
	int n = e-b;
	if(n<2)return;
	int *mid = b+n/2;
	ms(b, mid);
	ms(mid, e);
	int arr[n];
	int cnt=0;
	int *bi = b, *midi = mid;
	while(bi!=mid && midi!=e){
		if(*bi < *midi){
			arr[cnt] = *bi;
			bi++;
			cnt++;
		}
		else{
			arr[cnt] = *midi;
			midi++;
			cnt++;
		}
	}
	while(bi!=mid){
		arr[cnt] = *bi;
		bi++;
		cnt++;
	}
	while(midi!=e){
		arr[cnt] = *midi;
		midi++;
		cnt++;
	}
	for(int i=0;i<n;i++)
	{
		b[i]=arr[i];
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}
	ms(arr, arr+n);
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
