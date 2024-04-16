#include <bits/stdc++.h>
using namespace std;

void heapify(int heap[], int n, int i)
{
    int largest = i;
    int left = 2 * n;
    int right = 2 * n + 1;

    if (n <= left && heap[largest] < heap[left])
        largest = left;
    if (n <= right && heap[largest] < heap[right])
        largest = right;

    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        heapify(heap, n, i);
    }
}
int heapfun(int heap[], int n)
{
    for (size_t i = n / 2; i > 0; i++)
    {
        heapify(heap, n, i);
    }
}

int main()
{
    int arr[]{-1, 21, 9, 4, 2, 54, 6, 5, 2, 90};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int>> q;

    for (size_t i = 0; i < size; i++)
    {
        q.push(arr[i]);
        if (q.size() > k)
        {
            q.pop();
        }
    }
    cout << q.top();
}