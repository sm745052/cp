#include<bits/stdc++.h>
using namespace std;




#define ll long long


int main(){
    int arr[] = {1, 3, 7};
    int bits[32];
    memset(bits, 0, sizeof(bits));

    int n;
    for(int i=0;i<(n=sizeof(arr)/sizeof(arr[0]));i++){
        for(int j=0;j<32;j++){
            bits[j] += ((1<<j)&(arr[i]))!=0;
        }
    }
    ll ans = 0;
    for(int j=0;j<32;j++){
        ans += (ll)(bits[j] * (n-bits[j]))*(1ll<<j);
    }
    cout<<ans<<endl;
}