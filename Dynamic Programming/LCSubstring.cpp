#include <bits/stdc++.h>
using namespace std;

int LCSubstring(string x, string y, int m, int n)
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
                dp[i][j] = 0;
        }
    }
    int maxi = INT_MIN;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

int main()
{
    string s1 = "adityaa";
    string s2 = "adixxxtyaa";
    cout << LCSubstring(s1, s2, s1.size(), s2.size());
}