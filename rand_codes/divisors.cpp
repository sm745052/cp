#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 100;
    vector<int> g1;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            g1.push_back(i);
            if(i*i!=n)g1.push_back(n/i);
        }
    }
    sort(g1.begin(), g1.end());
    for(auto &i:g1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}