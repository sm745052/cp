#include<stdio.h>
#include<stdlib.h>
struct node{
	int row;
	int column;
	int value;
	struct node *next;
};

typedef struct node node;


node* insert(node* p, int r, int c, int v)
{
	node *tmp = (node*) malloc(sizeof(node));
	tmp->row = r;
	tmp->column = c;
	tmp->value = v;
	p->next = tmp;
	return tmp;
}



node* add(node *h1,node *h2)
{
	node *h = (node*) malloc(sizeof(node));
	node *t = h;
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->row==h2->row && h1->column==h2->column)
		{
			t = insert(t, h1->row, h2->column, h1->value+h2->value);
			h1 = h1->next;
			h2 = h2->next;
		}
		else
		{
			node *min;
			if(h1->row<h2->row)
				{min = h1; h1 = h1->next;}
			else if(h2->row<h1->row)
				{min = h2; h2 = h2->next;}
			else
			{
				if(h1->column<h2->column)
					{min = h1; h1 = h1->next;}
				else
					{min = h2;h2 = h2->next;}
			}
			t = insert(t, min->row, min->column, min->value);
		}
	}
	while(h1!=NULL)
	{
		t = insert(t, h1->row, h1->column, h1->value);
		h1 = h1->next;
	}
	while(h2!=NULL)
	{
		t = insert(t, h2->row, h2->column, h2->value);
		h2 = h2->next;
	}
	return h->next;
}

node* mult(node* h1, node* h2, int n)
{
	node* nh = (node*)malloc(sizeof(node));
	node* nhtrav = nh;
	node* h2trav = h2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			node* h1trav = h1;
			int val = 0;
			while(h1trav->row!=i)
			{
				h1trav = h1trav->next;
			}
			while(h1trav!=NULL && h1trav->row == i)
			{
				node* h2trav = h2;
				while(h2trav!=NULL)
				{
					if(h2trav->column == j)
					{
						if(h2trav->row == h1trav->column)
						{
							val += h2trav->value * h1trav->value;
							break;
						}
					}
					h2trav = h2trav->next;
				}
				h1trav = h1trav->next;
			}
			if(val)
			{
				nhtrav = insert(nhtrav, i, j, val);
			}
		}
	}
	return nh->next;
}




int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int arr1[n][n], arr2[n][n];
	printf("enter arr1\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("enter arr2\n");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        scanf("%d", &arr2[i][j]);
                }
        }
	node* h1 = (node*) malloc(sizeof(node));
	node *p = h1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				h1->row = i;
				h1->column = j;
				h1->value = arr1[i][j];
			}
			else
			{
				if(arr1[i][j]!=0)
				{
					p = insert(p, i, j, arr1[i][j]);
				}
			}
		}
	}
	node* h2 = (node*) malloc(sizeof(node));
	p = h2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				h2->row = i;
				h2->column = j;
				h2->value = arr2[i][j];
			}
			else
			{
				if(arr2[i][j]!=0)
				{
					p = insert(p, i, j, arr2[i][j]);
				}
			}
		}
	}
	node *res = add(h1, h2);
	printf("Addition --\n");
	while(res!=NULL)
	{
		printf("row = %d, column = %d, value = %d\n", res->row, res->column, res->value);
		res = res->next;
	}
	printf("Multiplication --\n");
	res = mult(h1, h2, n);
	while(res!=NULL)
	{
		printf("row = %d, column = %d, value = %d\n", res->row, res->column, res->value);
		res = res->next;
	}
	return 0;
}
