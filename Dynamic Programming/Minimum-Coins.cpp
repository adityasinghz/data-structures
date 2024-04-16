#include <bits/stdc++.h>

using namespace std;

int MinimumCoinChange(vector<int> &a, int n)
{
    int dp[a.size() + 1][n + 1];
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        if (j % a[0] == 0)
            dp[1][j] = j / a[0];
        else
            dp[1][j] = INT_MAX - 1;
    }

    for (int i = 2; i <= a.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= a[i - 1])
                dp[i][j] = min(1 + dp[i][j - a[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return (dp[a.size()][n] == INT_MAX - 1) ? -1 : dp[a.size()][n];
}

int main()
{
    vector<int> A{2, 5, 10, 1};
    cout << MinimumCoinChange(A, 27);
}