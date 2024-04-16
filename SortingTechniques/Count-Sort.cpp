#include <bits/stdc++.h>
using namespace std;

int C[1000];

void countsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        C[arr[i]]++;

    int k = 0;
    for (int i = 0; i < 1000; i++)
    {
        while (C[i]--)
        {
            arr[k++] = i;
        }
    }
}

int main()
{
    memset(C, 0, sizeof(C));

    int arr[]{1, 21, 9, 300, 4, 2, 54, 6, 5, 2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    countsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}