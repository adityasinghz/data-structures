#include <bits/stdc++.h>

using namespace std;

int merge(int arr[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[h + 1];
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= h)
        b[k++] = arr[j++];

    for (int i = l; i <= h; i++)
    {
        arr[i] = b[i];
    }
}

int mergesort(int arr[], int i, int n)
{
    if (i < n)
    {
        int mid = i + (n - i) / 2;
        mergesort(arr, i, mid);
        mergesort(arr, mid + 1, n);
        merge(arr, i, mid, n);
    }
}

int main()
{
    int arr[]{-1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}