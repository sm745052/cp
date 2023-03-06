#include<stdio.h>
#include<stdlib.h>




typedef struct nn{
    int val, c;
    struct nn *p, *l, *r;
}node;

node* BST;


void class1(node *tr){
    if(tr->p->p->c ==1){
        tr->p->p->c = 0;
        tr->p->p->r->c = 0;
    }
}


void LEFT_ROTATE(node* x){
    node* y = x->r;
    x->r = y->l;
    y->l->p = x;
    y->p = x->p;
    if(x->p==NULL){
        BST=y;
    }
    else if(x==x->p->l){
        x->p->l = y;
    }
    else{
        x->p->r = y;
    }
    y->l = x;
    x->p = y;
}



void RIGHT_ROTATE(node* x){
    node* y = x->l;
    x->l = y->r;
    y->r->p = x;
    y->p = x->p;
    if(x->p==NULL){
        BST=y;
    }
    else if(x==x->p->r){
        x->p->r = y;
    }
    else{
        x->p->l = y;
    }
    y->r = x;
    x->p = y;
}



void insert(int v){
    if(BST==NULL){
        node* n = (node*) malloc(sizeof(node));
        BST = n;
        n->l = (node*) malloc(sizeof(node));
        n->r = (node*) malloc(sizeof(node));
        n->val = v;
        n->c = 1;
        n->l->val = 1e9;
        n->l->c = 0;
        n->r->c = 0;
        n->l->p = n;
        n->r->val = 1e9;
        n->r->p = n;
    }
    else{
        node *tr = BST;
        while(tr->val!=1e9){
            if(tr->val>v){
                tr = tr->l;
            }
            else{
                tr = tr->r;
            }
        }
        tr->val = v;
        tr->c = 1;
        tr->l = (node*) malloc(sizeof(node));
        tr->r = (node*) malloc(sizeof(node));
        tr->l->val = 1e9;
        tr->l->c = 0;
        tr->l->p = tr;
        tr->r->val = 1e9;
        tr->r->p = tr;
        tr->r->c = 0;


        while(tr!=BST && tr->p->c==1){
            if(tr->p==tr->p->p->l){
                node* y = tr->p->p->r;
                if(y->c==1){
                    tr->p->c=0;
                    y->c=0;
                    tr->p->p->c = 1;
                    tr = tr->p->p;
                }
                else if(tr==tr->p->r){
                    tr = tr->p;
                    LEFT_ROTATE(tr);
                }
                tr->p->c = 0;
                tr->p->p->c = 1;
                RIGHT_ROTATE(tr->p->p);
            }
            else{
                node* y = tr->p->p->l;
                if(y->c==1){
                    tr->p->c=0;
                    y->c=0;
                    tr->p->p->c = 1;
                    tr = tr->p->p;
                }
                else if(tr==tr->p->l){
                    tr = tr->p;
                    RIGHT_ROTATE(tr);
                }
                tr->p->c = 0;
                tr->p->p->c = 1;
                LEFT_ROTATE(tr->p->p);
            }
        }
    }
}



void traversal(node *tr){
    if(tr->val == 1e9)return;
    traversal(tr->l);
    printf("%d ", tr->val);
    traversal(tr->r);
}





int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }
    traversal(BST);
    return 0;
}
