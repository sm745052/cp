#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define PN no()
#define PY yes()
#define v_inp(a) for(auto &i:a)cin>>i
#define v_print(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" \n"[i==a.size()-1];
#define s_print(a) for(auto i:a)cout<<i<<" ";cout<<endl;
#define pb push_back
#define v_sort(a) sort(a.begin(), a.end());
#define v_lb(a, x) lower_bound(a.begin(), a.end(), x)
#define v_ub(a, x) upper_bound(a.begin(), a.end(), x)
#define v_accumulate(a, x) accumulate(a.begin(), a.end(), x)
#define rep(i, l, r) for(int i=l;i<r;i++)
#define ll_max LLONG_MAX
#define ll_min LLONG_MIN

template<class T>
vector<T> v_psum(vector<T> a){
    vector<T> prefix(a.begin(), a.end());
    for(int i=1;i<a.size();i++)prefix[i]+=prefix[i-1];
    return prefix;
}

void no(){
    cout<<"No"<<endl;
}
void yes(){
    cout<<"Yes"<<endl;
}

// --------------------------------------------------------------------


vector<vector<vector<int>>>dp;

int f(string &s, int x, int id, int tight){
    if(x<0)return 0;
    if(dp[x][id][tight]!=-1)return dp[x][id][tight];
    if(id==s.size()-1){
        if(x>=0 && x<=((tight)?(s[id]-'0'):9))return dp[x][id][tight]=1;
        return dp[x][id][tight]=0;
    }
    int ub = (tight)?(s[id]-'0'):9;
    int ans = 0;
    for(int i=0;i<=ub;i++){
        ans += f(s, x-i, id+1, (tight & (i==(s[id]-'0'))));
    }
    return dp[x][id][tight]=ans;
}


signed main(){
    dp.clear();
    string R = "20356523542364365435636";
    int x = 9;
    dp = vector<vector<vector<int>>>(x+10, vector<vector<int>>(R.size()+10, vector<int>(2, -1)));
    cout<<f(R, x, 0, 1)<<endl;
    return 0;
}
