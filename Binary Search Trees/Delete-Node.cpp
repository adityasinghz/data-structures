#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
} * root;

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

    while (q != NULL)
    {
        r = q;
        if (q->data < key)
            q = q->right;
        else if (q->data > key)
            q = q->left;
        else
            return;
    }
    if (key > r->data)
        r->right = newNode;
    else
        r->left = newNode;
}

int Height(Node *p)
{
    int x, y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    return x > y ? x + 1 : y + 1;
}

Node *Succ(Node *p)
{
    while (p && p->right)
        p = p->right;
    return p;
}

Node *Incc(Node *p)
{
    while (p && p->left)
        p = p->left;
    return p;
}

void Inorder(Node *root)
{
    if (root)
    {
        Inorder(root->left);
        cout << root->data << ' ';
        Inorder(root->right);
    }
}

Node *Delete(Node *p, int key)
{
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->left == nullptr && p->right == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if (p->data > key)
        p->left = Delete(p->left, key);
    else if (p->data < key)
        p->right = Delete(p->right, key);
    else
    {
        if (Height(p->left) > Height(p->right))
        {
            q = Incc(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = Succ(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}

int main()
{
    int arr[]{1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(root, arr[i]);
    }
    Delete(root, 9);

    Inorder(root);
}