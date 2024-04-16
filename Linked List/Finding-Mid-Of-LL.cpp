#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *next;
    int data;
} *first = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = key;
    if (first == NULL)
    {
        first = newNode;
        return;
    }
    Node *q = p;
    while (q->next)
        q = q->next;

    q->next = newNode;
}

int findMid(Node *p)
{
    Node *fast = p;
    Node *slow = p;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void Display(Node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        Display(p->next);
    }
}

int main()
{
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(first, arr[i]);
    }

    cout << findMid(first) << ' ';
}