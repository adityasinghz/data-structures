#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
};

void Insert(int num, Node *&root)
{
    Node *newNode = new Node;
    newNode->left = nullptr;
    newNode->data = num;
    newNode->right = nullptr;

    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node *q = root;
    Node *r;
    while (q)
    {
        r = q;
        if (q->data < num)
            q = q->right;
        else if (q->data > num)
            q = q->left;
        else
            return;
    }
    if (r->data < num)
        r->right = newNode;
    else
        r->left = newNode;
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
    Node *root = nullptr;
    vector<int> vec{1, 2, 7, 3, 4, 5};
    for (int i = 0; i < vec.size(); i++)
    {
        Insert(vec[i], root);
    }
    Inorder(root);
}