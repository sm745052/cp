#include<bits/stdc++.h>
using namespace std;


int is_subseq(string a, string b, int m, int n){
    if(m==0)return 1;
    if(n==0)return 0;
    if(a[m-1]==b[n-1]){
        return max(is_subseq(a, b, m, n-1), is_subseq(a, b, m-1, n-1));
    }
    return is_subseq(a, b, m, n-1);
}


int main(){
    string a = "asd";
    string b = "afgshdfdjfhgjghjsfhajsfhd,d";
    cout<<is_subseq(a, b, a.length(), b.length())<<endl;
    return 0;
}