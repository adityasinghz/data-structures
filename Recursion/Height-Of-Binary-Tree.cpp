#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
} *root = nullptr;

Node *InsertBinary(Node *p, int key)
{
    if (p == nullptr)
    {
        Node *t = new Node;
        t->left = nullptr;
        t->data = key;
        t->right = nullptr;
        return t;
    }
    if (key < p->data)
        p->left = InsertBinary(p->left, key);
    else
        p->right = InsertBinary(p->right, key);

    return p;
}

void Inorder(Node *first)
{
    if (first)
    {
        Inorder(first->left);
        cout << first->data << ' ';
        Inorder(first->right);
    }
}

int BSTheight(Node *root)
{
    if (root == nullptr)
        return 0;
    int r = BSTheight(root->right);
    int l = BSTheight(root->left);
    return 1 + max(r, l);
}

int main()
{

    root = InsertBinary(root, 30);
    root = InsertBinary(root, 10);
    root = InsertBinary(root, 20);
    root = InsertBinary(root, 0);
    root = InsertBinary(root, 25);
    root = InsertBinary(root, 13);
    root = InsertBinary(root, 1);
    root = InsertBinary(root, 2);
    root = InsertBinary(root, 300);

    cout << "Sorted Array : ";
    Inorder(root);
    cout << "\n Height of BST : " << BSTheight(root);
}