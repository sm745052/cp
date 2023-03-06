#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7

typedef struct foo{
    int maps, mass, mas, sum, spr, ssl, sl, sr;
    foo(){
    }
    foo(int maps, int mas, int mass, int sum){
        this->maps=maps;
        this->mas=mas;
        this->mass=mass;
        this->sum=sum;
    }
}node;


int arr[10001];
node t[40004];


void build(int id, int l, int r){
    if(l==r){
        if(arr[l]<0){
            t[id].maps=0;
            t[id].mas=0;
            t[id].mass=0;
            t[id].sum=arr[l];
            t[id].sl=l;
            t[id].sr=r;
            t[id].spr=l-1;
            t[id].ssl=r+1;
        }
        else{
            t[id].maps=arr[l];
            t[id].mas=arr[l];
            t[id].mass=arr[l];
            t[id].sum=arr[l];
            t[id].sl=l;
            t[id].sr=r;
            t[id].spr=l;
            t[id].ssl=r;
        }
        return;
    }

    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);



    if(t[2*id+1].mass > t[2*id+1].sum+t[2*id].mass){
        t[id].mass = t[2*id+1].mass;
        t[id].ssl = t[2*id+1].ssl;
    }
    else{
        t[id].mass = t[2*id].mass+t[2*id+1].sum;
        t[id].ssl = t[2*id].sl;
    }
    t[id].sum=t[2*id].sum+t[2*id+1].sum;

    if(t[2*id].maps> t[2*id].sum+t[2*id+1].maps){
        t[id].maps = t[2*id].maps;
        t[id].spr=t[2*id].spr;
    }
    else{
        t[id].maps = t[2*id].sum+t[2*id+1].maps;
        t[id].spr = t[2*id+1].spr;
    }
    if(t[2*id].mas > max(t[2*id+1].mas, t[2*id].mass+t[2*id+1].maps)){
        t[id].mas = t[2*id].mas;
        t[id].sl=t[2*id].sl;
        t[id].sr=t[2*id].sr;
    }
    else{
        if(t[2*id+1].mas> t[2*id].mass+t[2*id+1].maps){
            t[id].mas = t[2*id+1].mas;
            t[id].sl=t[2*id+1].sl;
            t[id].sr=t[2*id+1].sr;
        }
        else{
            t[id].mas = t[2*id].maps+t[2*id+1].mass;
            t[id].sl=t[2*id].ssl;
            t[id].sr=t[2*id+1].spr;
        }
    }
}



node query(int id, int l, int r, int ql, int qr){
    cout<<"querying"<<l<<"--"<<r<<endl;
    node tmp(0, 0, 0, 0);
    if(ql<=l && qr>=r){
        return t[id];
    }
    if(qr<l || ql>r){
        return tmp;
    }
    int mid = (l+r)/2;
    node k1 = query(2*id, l, mid, ql, qr), k2 = query(2*id+1, mid+1, r, ql, qr);


    if(k2.mass > k2.sum+k1.mass){
        tmp.mass = k2.mass;
        tmp.ssl = k2.ssl;
    }
    else{
        tmp.mass = k1.mass+k2.sum;
        tmp.ssl = k1.ssl;
    }

    tmp.sum=k1.sum+k2.sum;

    if(k1.maps> k1.sum+k2.maps){
        tmp.maps = k1.maps;
        tmp.spr = k1.spr;
    }
    else{
        tmp.maps = k1.sum+k2.maps;
        tmp.spr = k2.spr;
    }
    if(k1.mas > max(k2.mas, k1.mass+k2.maps)){
        tmp.mas = k1.mas;
        tmp.sl= k1.sl;
        tmp.sr= k1.sr;
    }
    else{
        if(k2.mas> k1.mass+k2.maps){
            tmp.mas = k2.mas;
            tmp.sl = k1.sl;
            tmp.sr = k2.sr;
        }
        else{
            tmp.mas = k1.maps+k2.mass;
            tmp.sl=k1.ssl;
            tmp.sr=k2.spr;
        }
    }
    return tmp;
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
    for(int i=0;i<4*n;i++){
        cout<<"mass = "<<(t[i].mass)<<", "<<"maps = "<<t[i].maps<<", "<<"mas = "<<t[i].mas<<", sum = "<<t[i].sum<<endl;
    }
    cout<<endl;




    cout<<"-------------------------------------------------------------------------\n";




    cout<<query(1, 0, 4, 0, 3).mas<<" with segment = ["<<query(1, 0, 4, 0, 3).sl<<" "<<query(1, 0, 4, 0, 3).sr<<"]"<<endl;
}







signed main() {


#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}