#include<stdio.h>
#include<stdlib.h>

int K;




typedef struct n{
	int val;
	struct n* next;
}node;


node** table;

int hash(int n){
	return n%K;
}


void insert(int n){
	node** head = &table[hash(n)];
	node* newnode = (node*) malloc(sizeof(node));
	newnode->val = n;
	newnode->next = *head;
	*head = newnode;
}




int search(int n){
	node** head = &table[hash(n)];
	node* tr = *head;
	if(*head==NULL)return 0;
	do{
		if(tr->val==n)return 1;
		tr = tr->next;
	}while(tr!=NULL);
	return 0;
}






void delete(int n){
	printf("deleting %d\n", n);
	node** head = &table[hash(n)];
	node* ptr = NULL;
	node* tr = *head;
	
	while(tr!=NULL){

		if(tr->val==n){
			if(ptr==NULL){
				*head = tr->next;
				return;
			}
			else{
				ptr->next = tr->next;
				return;
			}
		}

		if(ptr==NULL){
			ptr = *head;
		}
		else{
			ptr = ptr->next;
		}
		tr = tr->next;
	}
}






node** create(){
	node** table = (node**)malloc((sizeof(node*)*K));
	for(int i=0;i<K;i++){
		table[i] = NULL;
	}
	return table;
}




void print_linkedlist(node* head){
	while(head!=NULL){
		printf("%d ", head->val);
		head = head->next;
	}
}





void print_table(node** table){
	printf("printing table\n");
	for(int i=0;i<K;i++){
		printf("%d ->", i);
		print_linkedlist(table[i]);
		printf("\n");
	}
}








int main(){
	K = 10;
	int n = 77;
	printf("creating\n");
	table = create();
	printf("inserting\n");
	insert(22);
	insert(12);
	print_table(table);
	delete(22);
	print_table(table);
	delete(22);
	print_table(table);
	return 0;
}