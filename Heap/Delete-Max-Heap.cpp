#include <bits/stdc++.h>
using namespace std;

void Insert(int heap[], int key, int n)
{
    int i = n;
    while (i >= 2 && heap[i / 2] < key)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = key;
}

void Delete(int heap[], int &size)
{
    heap[1] = heap[size - 1];
    size--;
    int i = 1;

    while (i < size)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        int large = heap[r] > heap[l] ? r : l;
        if (heap[large] > heap[i])
        {
            swap(heap[i], heap[large]);
            i = large;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int arr[]{-1, 21, 9, 4, 2, 54, 6, 5, 2, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int heap[size];
    for (int i = 1; i < size; i++)
        Insert(heap, arr[i], i);

    Delete(heap, size);
    Delete(heap, size);
    for (int i = 1; i < size; i++)
    {
        cout << heap[i] << ' ';
    }
}