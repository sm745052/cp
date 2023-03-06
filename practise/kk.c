#include<stdio.h>
#include<stdlib.h>

typedef struct nn{
	int v;
	struct nn *p, *l, *r;
}node;


node *BST;


void insert(int v){
	if(BST==NULL){
		node *n = (node*)malloc(sizeof(node));
		n->r=(node*)malloc(sizeof(node));
		n->l=(node*)malloc(sizeof(node));
		n->v=v;
		n->p=NULL;
		n->r->v = 1e9;
		n->r->p = n;
		n->l->p = n;
		n->l->v = 1e9;
		BST=n;
	}
	else{
		node *tr=BST;
		while(tr->v!=1e9){
			if(tr->v < v){
				tr = tr->r;
			}
			else{
				tr = tr->l;
			}
		}
                tr->r=(node*)malloc(sizeof(node));
                tr->l=(node*)malloc(sizeof(node));
                tr->v=v;
                tr->r->v = 1e9;
                tr->r->p = tr;
                tr->l->p = tr;
                tr->l->v = 1e9;
	}
}



void traverse(node *p){
	if(p->v==1e9)return;
	traverse(p->l);
	printf("%d ", p->v);
	traverse(p->r);
	if(p==BST)printf("\n");
}



node* search(node* p, int v){
	if(p->v==1e9)return NULL;
	if(p->v==v){
		return p;
	}
	else{
		if((p->v)<v)
			return search(p->r, v);
		return search(p->l, v);
	}
}


node* max(node* p){
	if(p->r->v==1e9 && p->l->v==1e9)return p;
	if(p->r->v==1e9)return p;
	return max(p->r);
}


node* min(node* p){
	if(p->l->v==1e9 && p->r->v==1e9)return p;
        if(p->l->v==1e9)return p;
        return min(p->l);
}


void delete(int v){
	node *n = search(BST, v);
	if(n==NULL){
		printf("not found\n");
		return;
	}
	//case1
	if(n->r->v==1e9 && n->l->v ==1e9){
		n->v=1e9;
		if(n->p==NULL){
			BST = NULL;
		}
	}
	//case2
	else if(n->r->v==1e9){
		node *l_max = max(n->l);
                n->v = l_max->v;
                l_max->v = 1e9;

	}
	else if(n->l->v==1e9){
		printf("hello");
		node *r_min = min(n->r);
		printf("%d", min(n->r)->v);
                n->v = r_min->v;
                r_min->v = 1e9;
	}
	//case3
	else{
		node *r_min = min(n->r);
		n->v = r_min->v;
		r_min->v = 1e9;
	}
}


int main(){
	int n, d;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
		insert(arr[i]);
	}
	traverse(BST);
	scanf("%d", &d);
	delete(d);
	traverse(BST);
	return 0;
}
