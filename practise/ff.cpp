#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7




typedef struct nn{
    int val;
    struct nn *p, *l, *r;
    int g;
}node;

node* BST;


int insert(int v){
    int cnt = 0;
    if(BST==NULL){
        node* n = (node*) malloc(sizeof(node));
        BST = n;
        n->l = (node*) malloc(sizeof(node));
        n->r = (node*) malloc(sizeof(node));
        n->val = v;
        n->g=0;
        n->l->val = 1e9;
        n->l->p = n;
        n->l->g = 1e9;
        n->r->val = 1e9;
        n->r->p = n;
        n->r->g = 1e9;
        cnt=0;
    }
    else{
        node *tr = BST;
        while(tr->val!=1e9){
            if(tr->val>v){
                tr = tr->l;
            }
            else{
                (tr->g)++;
                tr = tr->r;
            }
        }
        tr->val = v;
        tr->l = (node*) malloc(sizeof(node));
        tr->r = (node*) malloc(sizeof(node));
        if(tr==tr->p->l){
            tr->g=tr->p->g+1;
        }
        else{
            tr->g=tr->p->g-1;
        }
        tr->l->val = 1e9;
        tr->l->p = tr;
        tr->r->val = 1e9;
        tr->r->p = tr;
        cnt = tr->g;
    }
    return cnt;
}








void solve(int test){
    BST=NULL;

    int n, m, k;
    cin>>n>>m>>k;
    int arr[k+1];
    int garr[k+1];
    map<int, int>ind;
    for(int i=1;i<=k;i++){
        cin>>arr[i];
        garr[i]=insert(arr[i]);
        cout<<garr[i]<<" ";
        ind[arr[i]]=i;
    }
    cout<<endl;
    for(int i=k;i>=1;i--){
        if(ind[i]-1-garr[ind[i]]>n*m-3){
            cout<<"tidak"<<endl;
            return;
        }
    }
    cout<<"ya"<<endl;
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