#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7



int arr[100100];
int t[400400];



void build(int id, int l, int r){
    if(l==r){
        t[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    t[id] = max(t[2*id], t[2*id+1]);
}



int query(int id, int l, int r, int ql, int qr){
    if(ql<=l && qr>=r){
        return t[id];
    }
    if(l>qr || r<ql){
        return 0;
    }
    int mid = (l+r)/2;
    int sl = query(2*id, ql, qr, l, mid);
    int sr = query(2*id+1, ql, qr, mid+1, r);
    return max(sl, sr);
}


void update(int ind, int l, int r, int pos, int v){
    if(l==r){
        t[ind] = v;
        arr[l] = v;
        return;
    }
    int mid = (l+r)/2;
    if(mid>=pos)
        update(2*ind, l, mid, pos, v);
    else
        update(2*ind+1, mid+1, r, pos, v);
    t[ind] = max(t[2*ind], t[2*ind+1]);
}



void solve(int test){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array = ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    build(1, 0, n-1);
    for(int i=0;i<3*n;i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;




    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<i<<" se "<<j<<" = "<<query(1, 0, n-1, i, j)<<endl;
        }
    }

    update(1, 0, n-1, 2, 30);
    cout<<"updated\n";


    cout<<"\nnew array = ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<3*n;i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;




    cout<<query(1, 0, n-1, 3, 4)<<endl;
}







signed main() {


#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}