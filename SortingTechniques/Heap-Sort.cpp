#include <bits/stdc++.h>

using namespace std;

int heapify(int arr[], int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
        largest = l;
    if (r < n && arr[largest] < arr[r])
        largest = r;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

int heapsort(int arr[], int i, int n)
{
    for (int i = 2 * n - 1; i >= 0; i--)
        heapify(arr, i, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main()
{
    int arr[]{-1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}