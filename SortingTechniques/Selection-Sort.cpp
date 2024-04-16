#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        int j = i;
        for (; j < n; j++)
        {
            if (arr[k] > arr[j])
                k = j;
        }
        swap(arr[k], arr[i]);
    }
}

int main()
{
    int arr[]{-1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}