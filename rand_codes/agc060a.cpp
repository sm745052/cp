#include<bits/stdc++.h>
using namespace std;
#define int long long

int t[60][200][200];


int f(string &s, int n, char n_2, char n_1){
    if(t[n][n_2][n_1]!=-1)return t[n][n_2][n_1];
    if(s[n-1]!='?' && s[n-1]!=n_1){
        return t[n][n_2][n_1] = 0;
    }
    if(n==1){
        return t[n][n_2][n_1] = 1;
    }
    if(n==2){
        if(s[n-1]!='?'){
            if(s[n-2]!='?'){
                return t[n][n_2][n_1] = (n_1==s[n-1]) && (n_2==s[n-2]) && (n_1!=n_2);
            }
            return t[n][n_2][n_1] = n_2!=n_1 && n_1==s[n-1];
        }
        if(s[n-2]!='?'){
            return t[n][n_2][n_1] = (n_2==s[n-2]) && (n_1!=n_2);
        }
        return t[n][n_2][n_1] = n_1!=n_2;
    }
    if(n_1=='?'){
        int res = 0;
        for(int i='a';i<='z';i++){
            if(n_2=='?'){
                for(int j='a';j<='z';j++){
                    for(int k='a';k<='z';k++){
                        if(k!=j && j!=i && i!=k)
                            res = (res + f(s, n-1, k, j))%998244353;
                    }
                }
            }
            else{
                for(int k='a';k<='z';k++){
                    if(k!=n_2 && n_2 !=i && i!=k)
                        res = (res + f(s, n-1, k, n_2))%998244353;
                }
            }
        }
        return t[n][n_2][n_1] = res;
    }
    int res=0;
    if(n_2=='?'){
        for(int j='a';j<='z';j++){
            for(int k='a';k<='z';k++){
                if(k!=j && j!=n_1 && n_1!=k)
                    res = (res + f(s, n-1, k, j))%998244353;
            }
        }
    }
    else{
        for(int k='a';k<='z';k++){
            if(k!=n_2 && n_2 !=n_1 && n_1!=k)
                res = (res + f(s, n-1, k, n_2))%998244353;
        }
    }
    return t[n][n_2][n_1] = res%998244353;
}

signed main(){
    memset(t, -1, sizeof(t));
    int n;
    string s;
    cin>>n>>s;
    cout<<f(s, n, s[n-2], s[n-1])<<endl;
    return 0;
}