#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7



struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
    int size;
};

int max(int a, int b);

int height(struct node *N)
{
    if (N == NULL)
        return 0;
        
    return N->height;
}


int size(struct node *N)
{
    if (N == NULL)
        return 0;
        
    return N->size;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}



struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    // New node is initially added at leaf
    node->height = 1;
    node->size = 1;
    return(node);
}

// A utility function to right rotate
// subtree rooted with y
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Update sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;

    // Return new root
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;

    return y;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
        
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key,
                    int *count)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key, count);
    else
    {
        node->right = insert(node->right, key, count);

        *count = *count + size(node->left) + 1;
    }


    // 2.Update height and size of this ancestor node
    node->height = max(height(node->left),
                    height(node->right)) + 1;
    node->size = size(node->left) +
                size(node->right) + 1;

    int balance = getBalance(node);


    
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void constructLowerArray(int arr[], int countSmaller[],
                        int n)
{
    int i, j;
    struct node *root = NULL;
    for(i = 0; i < n; i++)
        countSmaller[i] = 0;
    for(i = n - 1; i >= 0; i--)
    {
        root = insert(root, arr[i], &countSmaller[i]);
    }
}







void solve(int test){
    int n, m, k;
    cin>>n>>m>>k;
    int arr[k];
    int narr[k];
    for(int i=0;i<k;i++){
        cin>>narr[k-1-i];
        arr[i] = narr[k-1-i];
    }
    int *low = (int *)malloc(sizeof(int)*k); 
    constructLowerArray(narr, low, k);
    int
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