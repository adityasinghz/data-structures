#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    int column;
    Node *col;
} *first = nullptr;

void ListInsert(Node *p, int row)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = row;
    newNode->col = nullptr;

    if (first == nullptr)
    {
        first = newNode;
        return;
    }
    Node *q = p;
    while (q->next)
        q = q->next;

    q->next = newNode;
}

void Display(Node *p, int row, int col)
{
    Node *q;
    while (p)
    {
        q = p;
        while (q)
        {
            cout << q->data << ' ';
            q = q->col;
        }
        cout << '\n';
        p = p->next;
    }
}

int main()
{
    int row = 6;
    int col = 5;
    int sparsh[row][col]{{0, 0, 0, 2, 0}, {1, 0, 0, 2, 3}, {1, 2, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 2, 3, 0, 0}, {2, 2, 0, 0, 0}};

    for (int i = 0; i < row; i++)
        ListInsert(first, i);

    Node *p = first;
    for (int i = 0; i < row; i++)
    {
        Node *q = p;
        for (int j = 0; j < col; j++)
        {
            if (sparsh[i][j] != 0)
            {
                Node *newNode = new Node;
                newNode->data = sparsh[i][j];
                newNode->column = j;
                newNode->col = nullptr;
                if (q->col == nullptr)
                    q->col = newNode;
                else
                {
                    while (q->col)
                        q = q->col;
                    q->col = newNode;
                }
            }
        }
        p = p->next;
    }
    Display(first, row, col);
}