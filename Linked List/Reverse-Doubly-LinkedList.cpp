#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->prev = NULL;
    newNode->data = key;
    newNode->next = NULL;

    if (first == nullptr)
    {
        first = newNode;
        return;
    }
    Node *q = p;
    while (q->next)
    {
        q = q->next;
    }
    q->next = newNode;
    newNode->prev = q;
}

void Reverse(Node *p)
{
    Node *last = p;
    while (last->next)
    {
        last = last->next;
    }
    while (last)
    {
        cout << last->data << ' ';
        last = last->prev;
    }
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
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        Insert(first, arr[i]);

    // Display(first);
    Reverse(first);
}