#include <bits/stdc++.h>
using namespace std;

void Insert(vector<int> &a, int temp)
{
    if (a.size() == 0 || a[a.size() - 1] <= temp)
        a.push_back(temp);
    else
    {
        int val = a[a.size() - 1];
        a.pop_back();
        Insert(a, temp);
        a.push_back(val);
    }
}
void Sort(vector<int> &a, int n)
{
    if (a.size() == 0)
        return;
    int temp = a[n - 1];
    a.pop_back();
    Sort(a, n - 1);
    Insert(a, temp);
}

int main()
{
    vector<int> a{23, 45, 12, 1, 9, 2};
    Sort(a, a.size());
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}