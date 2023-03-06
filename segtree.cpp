#include<bits/stdc++.h>
using namespace std;

int *arr;
int t[40040];


void build(int id, int l, int r){
    if(l==r)t[id]=arr[l];
    else{
        int mid = (l+r)/2;
        build(2*id, l, mid);
        build(2*id+1, mid+1, r);
        t[id] = t[2*id] + t[2*id+1];
    }
}


int query(int id, int l, int r, int ql, int qr){
    if(ql<=l && qr>=r){
        return t[id];
    }
    if(ql>r || qr<l){
        return 0;
    }
    int mid = (l+r)/2;
    return query(2*id, l, mid, ql, qr)+query(2*id+1, mid+1, r, ql, qr);
}


void update(int id, int l, int r, int pos, int val){
    if(l==r){
        t[id] = val;
        arr[l] = val;
        return;
    }
    int mid = (l+r)/2;
    if(mid>=pos){
        update(2*id, l, mid, pos, val);
    }
    else{
        update(2*id+1, mid+1, r, pos, val);
    }
    t[id] = t[2*id]+t[2*id+1];
}



int main(){
    int marr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(marr)/sizeof(marr[0]);
    arr=marr;
    build(1, 0, n-1);
    for(int id=0;id<=4*n;id++){
        cout<<t[id]<<" ";
    }
    cout<<endl;
    cout<<query(1, 0, n-1, 4, 6)<<endl;
    update(1, 0, n-1, 5, 5);
    for(int id=0;id<=4*n;id++){
        cout<<t[id]<<" ";
    }
    cout<<endl;
    cout<<query(1, 0, n-1, 4, 6)<<endl;
    return 0;
}