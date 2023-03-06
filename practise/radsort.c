#include<stdlib.h>
#include<stdio.h>


int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	int B[n];



	int d[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}


	for(int k=0;k<=9;k++){
		for(int i=0;i<n;i++){
			int tt=1;
			for(int ll=0;ll<k;ll++)
				tt *= 10;
			d[i] = (arr[i]/tt)%10;
//			printf("%d ", d[i]);
		}
		int C[10]={0};
		for(int i=0;i<n;i++){
			C[d[i]] = C[d[i]] + 1;
		}

		for(int i=1;i<=9;i++){
		C[i] = C[i] + C[i-1];
		}

		for(int j=n-1;j>=0;j--){
			B[C[d[j]]-1] = arr[j];
			C[d[j]]=C[d[j]]-1;
		}


		for(int i=0;i<n;i++){
			arr[i] = B[i];
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
