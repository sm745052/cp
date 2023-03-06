#include<bits/stdc++.h>
using namespace std;


int main(){
    int n = 1000001007;
    vector<pair<int, int> >g1;
    for(int i=2;i*i<=n;i++){
        int ctr=0;
        while(n%i==0){
            ctr++;
            n/=i;
        }
        g1.push_back({i, ctr});
    }
    if(n>2)g1.push_back({n, 1});
    for(int i=0;i<g1.size();i++)if(g1[i].second!=0)cout<<g1[i].first<<" --- "<<g1[i].second<<"\n";
    return 0;
}