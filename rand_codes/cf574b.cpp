#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, max, min;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    max = arr[n-1];
    min = arr[0];
    int revarr[n];
    for(int i=0; i<n; i++)
    {
        revarr[i] = arr[n-i-1];
    }
    for(int i=0; i<n; i++)
    {
        if(revarr[i] == )
    }

    return 0;
}
