#include <bits/stdc++.h>

using namespace std;

string LCS(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int i = m;
    int j = n;
    string res;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            res += x[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
                j--;
            else
                i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string x = "cbbd";
    string y = "dbbc";
    cout << LCS(x, y, x.size(), y.size());
}