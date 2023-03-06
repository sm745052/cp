#include<bits/stdc++.h>

using namespace std;



signed main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<int> n_prime(3000000+1, 0);
        int k=-1;
        for(int p=2;p*p<=3000000+1;p++){
            if(!n_prime[p]){
                for(int i=p*p;i<=3000000+1;i+=p){
                    n_prime[i] = 1;
                }
            }
        }
        for(int p=2;p<=3000000+1;p++){
            if(n_prime[p]==0 && n%p==0){
                k=p;
                break;
            }
        }
        long long p, q;
        // if(k==-1)cout<<"err"<<endl;
        if((n/k)%k==0)p=k, q=(n/k)/k;
        else q=k, p=long(sqrt((n/k)));
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}