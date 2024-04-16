#include <bits/stdc++.h>
using namespace std;

int parti(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            swap(arr[i], arr[j]);
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int i, int n)
{
    if (i < n)
    {
        int j = parti(arr, i, n);
        quicksort(arr, i, j);
        quicksort(arr, j + 1, n);
    }
}

int main()
{
    int arr[]{INT_MAX - 1, 4, 3, 8, 4, 6, 5, INT_MIN + 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
