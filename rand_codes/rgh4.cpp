#include<bits/stdc++.h>
using namespace std;

int n;
int t[1001];
int s[1001];
int x, k;
int ch[1001];

int rec(int i){
    //prune
    if(i>n-1)return 0;
    if(i==n-1){
        for(int j=0;j<n;j++){
            
        }
    }
    //iterate over choices
    ch[i] = 1;

}



void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i]>>s[i];
    }
    memset(ch, -1, sizeof(ch));
    cin>>x>>k;
    cout<<rec(0)<<endl;
}



int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}