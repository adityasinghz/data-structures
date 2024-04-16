#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
} *root = nullptr;

void Insert(Node *p, int data)
{
    Node *newNode = new Node;
    newNode->left = nullptr;
    newNode->data = data;
    newNode->right = nullptr;
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    queue<Node *> q;
    q.push(p);

    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (t->left)
            q.push(t->left);
        else
        {
            t->left = newNode;
            return;
        }
        if (t->right)
            q.push(t->right);
        else
        {
            t->right = newNode;
            return;
        }
    }
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

int main()
{
    int arr[]{1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        Insert(root, arr[i]);
    }
    Inorder(root);
}