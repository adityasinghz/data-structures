#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = nullptr, *second = nullptr;

void Insert(Node **p, int key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;

    if (*p == nullptr)
    {
        *p = newNode;
        return;
    }
    Node *q = *p;
    while (q->next)
    {
        q = q->next;
    }
    q->next = newNode;
}

void Concatenate(Node **p, Node **q)
{
    Node *r = *p;
    while (r->next)
        r = r->next;
    r->next = *q;
}
void Display(Node *p)
{
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
}

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int arr1[]{5, 6, 7, 8, 9};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr1) / sizeof(arr1[0]);
    for (size_t i = 0; i < m; i++)
        Insert(&first, arr[i]);

    for (size_t i = 0; i < n; i++)
        Insert(&second, arr1[i]);

    Concatenate(&first, &second);
    Display(first);
}
