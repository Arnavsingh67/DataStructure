#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    int height;
};

// Create new node
node* creatnode(int value)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;   // New node is initially at height 1
    return newnode;
}

// Height of node
int height(node* n)
{
    if(n == NULL)
        return 0;
    return n->height;
}

// Balance factor
int getBalance(node* n)
{
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// Right rotation (LL Case)
node* rightRotate(node* y)
{
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;  // new root
}

// Left rotation (RR Case)
node* leftRotate(node* x)
{
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  // new root
}

// AVL Insertion
node* AVLinsert(node* root, int value)
{
    if(root == NULL)
        return creatnode(value);

    if(value < root->data)
        root->left = AVLinsert(root->left, value);
    else if(value > root->data)
        root->right = AVLinsert(root->right, value);
    else
        return root; // duplicate values not allowed

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Case 1: Left Left
    if(balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Case 2: Right Right
    if(balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Case 3: Left Right
    if(balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left
    if(balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // unchanged node
}

// Inorder Traversal
void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    int n, value;

    cout << "How many nodes you want to create: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = AVLinsert(root, value);  // using AVL insert
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    return 0;
}
