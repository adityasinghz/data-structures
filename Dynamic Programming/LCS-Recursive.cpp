#include <bits/stdc++.h>

using namespace std;

int LCS(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (x[m - 1] == y[n - 1])
        return 1 + LCS(x, y, m - 1, n - 1);
    else
        return max(LCS(x, y, m - 1, n), LCS(x, y, m, n - 1));
}

int main()
{
    string x = "abcde";
    string y = "ace";
    cout << LCS(x, y, x.size(), y.size());
}