#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long




void solve(){
    int n;
    cin>>n;
    int arr[n];
    int ctr1=0, ctr2=0;
    int cost1[n]={0};
    int cost2[n]={0};
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr[i]=k;
        while(arr[i]%2==1){
            arr[i]/=2;
            cost1[i]+=1;
        }
        arr[i]=k;
        if(arr[i]%2)cost2[i] = INT_MAX;
        while(arr[i]%2==0){
            arr[i]/=2;
            cost2[i]+=1;
            if(arr[i]==0){
                cost2[i]=INT_MAX;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(cost1[i])ctr1++;
    }
    if((ctr1)%2==0){
        cout<<0<<endl;
        return;
    }
    sort(cost1, cost1+n);
    sort(cost2, cost2+n);
    int i=0;
    for(i=0;i<n;i++){
        // cout<<cost1[i]<<",";
        if(cost1[i]){
            i++;
            break;
        }
    }
    int j=0;
    for(j=0;j<n;j++){
        // cout<<cost2[j]<<",";
        if(cost2[j]){
            j++;
            break;
        }
    }
    cout<<min(cost1[i-1], cost2[j-1])<<"\n";
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