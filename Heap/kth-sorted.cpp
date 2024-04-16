#include <bits/stdc++.h>
using namespace std;

void kthsorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
    {
        q.push(arr[i]);
        if (q.size() > k)
        {
            cout << q.top() << ' ';
            q.pop();
        }
    }
}

int main()
{

    int arr[]{6, 5, 3, 2, 8, 9, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    kthsorted(arr, size, 3);
}