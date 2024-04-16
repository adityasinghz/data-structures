#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[]{-1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}