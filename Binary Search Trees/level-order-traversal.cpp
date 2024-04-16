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

void LevelOrderTraversal(Node *p)
{
    queue<Node *> que;
    que.push(root);
    cout << root->data << ' ';
    Node *q;
    while (!que.empty())
    {
        q = que.front();
        que.pop();
        if (q->left)
        {
            cout << q->left->data << ' ';
            que.push(q->left);
        }
        else
        {
            cout << q->right->data << ' ';
            que.push(q->right);
        }
    }
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
    int arr[]{1, 2, 345, 100, 32, 4};
    for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        Insert(root, arr[i]);
    }
    LevelOrderTraversal(root);
    // Inorder(root);
}