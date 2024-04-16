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
    newNode->next = nullptr;
    newNode->data = key;
    if (*p == nullptr)
    {
        *p = newNode;
        return;
    }
    Node *q = *p;
    while (q->next)
        q = q->next;
    q->next = newNode;
}

Node *Intersection(Node *head1, Node *head2)
{
    Node *L1 = head1;
    Node *L2 = head2;
    stack<Node *> stk1;
    stack<Node *> stk2;
    while (L1)
    {
        stk1.push(L1);
        L1 = L1->next;
    }
    while (L2)
    {
        stk2.push(L2);
        L2 = L2->next;
    }
    Node *res = nullptr;
    while ((!stk1.empty() && !stk2.empty()) && (stk1.top() == stk2.top()))
    {
        res = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    return res;
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
    int arr1[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[]{4, 5, 9, 3, 43};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < m; i++)
        Insert(&first, arr1[i]);
    for (int i = 0; i < n; i++)
        Insert(&second, arr2[i]);
    // Intersecting 2 Linked List
    int intersecting = 7;
    Node *h1 = first;
    Node *h2 = second;

    while (h1 && h1->data != intersecting)
    {
        h1 = h1->next;
    }
    while (h2->next)
    {
        h2 = h2->next;
    }
    h2->next = h1;
    Node *ans = Intersection(first, second);
    cout << ans->data;
}