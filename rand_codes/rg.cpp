#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int> cnt(3);
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]+1]++;
        s+=a[i];
    }
    cout<<cnt[0]<<endl;
    if(cnt[0]>0)cout<<s+2<<endl;
    else cout<<s-2<<endl;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
