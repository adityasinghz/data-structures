#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
} *root = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->left = nullptr;
    newNode->data = key;
    newNode->right = nullptr;
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node *q = p;
    Node *r;
    while (q)
    {
        r = q;
        if (q->data < key)
            q = q->right;
        else if (q->data > key)
            q = q->left;
        else
            return;
    }
    if (r->data < key)
        r->right = newNode;
    else
        r->left = newNode;
}

int search(Node *p, int key)
{
    if (p->data == key)
        return p->data;
    Node *q = p;
    while (q)
    {
        if (q->data == key)
            return q->data;
        else if (q->data < key)
            q = q->right;
        else
            q = q->left;
    }
    return -1;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->left);
        cout << p->data << ' ';
        Inorder(p->right);
    }
}

int main()
{
    int arr[]{1, 2002, 21, 4, 43, 101};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(root, arr[i]);
    }
    Inorder(root); // for checking purpose
    cout << search(root, 2002);
}