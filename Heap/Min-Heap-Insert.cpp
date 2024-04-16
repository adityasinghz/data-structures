#include <bits/stdc++.h>
using namespace std;

void Insert(int heap[], int key, int n)
{
    int i = n;
    while (i >= 2 && key < heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = key;
}

int main()
{
    int arr[]{-1, 21, 9, 4, 2, 54, 6, 5, 2, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int heap[size];
    for (int i = 1; i < size; i++)
    {
        Insert(heap, arr[i], i);
    }
    for (int i = 1; i < size; i++)
    {
        cout << heap[i] << ' ';
    }
}