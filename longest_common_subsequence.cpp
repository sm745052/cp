#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];


int lcs(string &s1, string &s2, int n, int m){
    if(t[n][m]!=-1)return t[n][m];
    if(n==0||m==0)return t[n][m]=0;
    if(s1[n-1]==s2[m-1]){
        return t[n][m]=1+lcs(s1, s2, n-1, m-1);
    }
    return t[n][m]=max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
}



int main(){
    memset(t, -1, sizeof(t));
    string s1 = "qmwertyauimoapto[sttghojktal;mzxafgmhj";
    string s2 = "";
    for(auto &i:s1){
        s2 = i+s2;
    }
    cout<<lcs(s1, s2, s1.length(), s2.length())<<endl;
    // for(int i=0;i<=s1.length();i++){
    //     for(int j=0;j<=s2.length();j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int i=s1.length(), j=s2.length();
    string s="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s = s1[i-1]+s;
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>=t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}