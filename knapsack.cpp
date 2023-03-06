#include<bits/stdc++.h>
using namespace std;

int t[10002][10002];



int knapsack(int W[], int C[], int n, int B){
    if(n==0 || B==0){
        return 0;
    }
    if(t[n][B]!=-1){
        return t[n][B];
    }
    if(W[n-1]<=B){
        return t[n][B] = max(C[n-1]+knapsack(W, C, n-1, B-W[n-1]), knapsack(W, C, n-1, B));
    }
    return t[n][B] = knapsack(W, C, n-1, B);
}



int main(){
    memset(t, -1, sizeof(t));
    int W[] = {1, 3, 4, 5, 3, 4, 5, 6, 78, 8, 6, 5, 4, 3, 2, 3, 5, 67, 87, 8, 7, 7, 7, 8, 9, 9};
    int C[] = {1, 5, 5, 7, 3, 4, 54, 56, 6, 7, 87, 8, 67, 8 , 9, 9, 78, 20, 30, 40 ,70 , 56 , 4, 8, 7, 78, 45};
    int B = 90;
    int n = sizeof(W)/sizeof(W[0]);
    cout<<knapsack(W, C, n, B)<<endl;
    return 0;
}