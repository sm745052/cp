#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define PN no()
#define PY yes()
#define v_inp(a) for(auto &i:a)cin>>i
#define v_print(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" \n"[i==a.size()-1];
#define v_print(a) for(auto i:a)cout<<i<<" ";cout<<endl;
#define pb push_back
#define v_sort(a) sort(a.begin(), a.end());
#define v_lb(a, x) lower_bound(a.begin(), a.end(), x)
#define v_ub(a, x) upper_bound(a.begin(), a.end(), x)
#define v_accumulate(a, x) accumulate(a.begin(), a.end(), x)
#define rep(i, l, r) for(int i=l;i<r;i++)
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




signed main(){
  int n, m;
  cin>>n>>m;
  for(int i=0;i<n;i++){

  }
  return 0;
}
