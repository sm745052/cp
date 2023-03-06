#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
 
 
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr+1, arr+n);
    if(arr[0]>=arr[n-1]){
        cout<<arr[0]<<endl;
        return;
    }
    while(lower_bound(arr+1, arr+n, arr[0])!=arr+n){
        int k = lower_bound(arr+1, arr+n, arr[0]) - arr;
        if(arr[0]!=arr[k]){
            int tmp = arr[0];
            arr[0] = ceil((arr[0]+arr[k])/2.0);
            arr[k] = floor((tmp+arr[k])/2.0)-1;
        }
        else{
            arr[k] = arr[0]-1;
        }
    }
    cout<<arr[0]<<endl;
}
 
 
 
int32_t main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}