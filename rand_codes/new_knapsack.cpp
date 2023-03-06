#include<bits/stdc++.h>
using namespace std;


int knapsack(int W[], int V[], int n, int B){
    if(n==0||B==0)return 0;
    if(W[n-1]<=B){
        return max(knapsack(W, V, n-1, B - W[n-1]) + V[n-1], knapsack(W, V, n-1, B));
    }
    return knapsack(W, V, n-1, B);
}

int main(){
    int W[] = {4, 3, 4, 7, 5, 6};
    int V[] = {23, 34, 45 ,23 ,34, 56};
    int B = 10;
    for(int i=0;i<B;i++)
        cout<<knapsack(W, V, sizeof(W)/sizeof(W[0]), i)<<endl;
    return 0;
}