#include <bits/stdc++.h>
using namespace std;

int CoinChange(vector<int> &a, int n)
{
    int dp[a.size() + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j > 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else if (a[i - 1] <= j)
                dp[i][j] = dp[i][j - a[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[a.size()][n];
}

int main()
{
    int n = 10;
    vector<int> arr{2, 5, 3, 6};
    cout << CoinChange(arr, n);
}