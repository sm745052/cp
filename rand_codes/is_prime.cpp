#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 11;
    vector<int> g1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}