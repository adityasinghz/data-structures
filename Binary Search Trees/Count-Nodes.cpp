#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
} *root;

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

int r_height(Node *p)
{
    int h = 0;
    while (p)
    {
        h++;
        p = p->right;
    }
    return h;
}
int l_height(Node *p)
{
    int h = 0;
    while (p)
    {
        h++;
        p = p->left;
    }
    return h;
}
int countNode(Node *p)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = r_height(p);
    y = l_height(p);
    if (x == y)
        return (1 << x) - 1;

    return 1 + countNode(p->left) + countNode(p->right);
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
    int arr[]{1, 21, 9, 300, 4, 54, 6, 5, 2, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < n; i++)
    {
        Insert(root, arr[i]);
    }

    cout << countNode(root) + 1 << ' ';
}