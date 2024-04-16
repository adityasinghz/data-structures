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
    Node *q = root;
    Node *r;
    while (q)
    {
        r = q;
        if (key > q->data)
            q = q->right;
        else if (key < q->data)
            q = q->left;
        else
            return;
    }
    if (r->data < key)
        r->right = newNode;
    else
        r->left = newNode;
}
void rPreorder(Node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        rPreorder(p->left);
        rPreorder(p->right);
    }
}

void Preorder(Node *p)
{
    stack<Node *> stk;
    Node *t = p;
    while (!stk.empty() || t != nullptr)
    {
        if (t != nullptr)
        {

            stk.push(t);
            t = t->left;
        }
        else
        {
            cout << t->data << ' ';
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
}

int main()
{
    int arr[]{8, 3, 5, 4, 9, 7, 2};
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        Insert(root, arr[i]);
    }
    Preorder(root);
}