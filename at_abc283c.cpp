#include<bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin>>s;
    int ctr=0;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            ctr++;
        }
        else{
            ans += ctr/2 + ctr%2 + 1;
            ctr=0;
        }
    }
    ans += ctr/2 + ctr%2;
    cout<<ans<<endl;
    return 0;
}