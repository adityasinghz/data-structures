#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int LCSMemo(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (dp[m][n] != -1)
        return dp[m][n];
    else if (x[m - 1] == y[n - 1])
        return dp[m][n] = 1 + LCSMemo(x, y, m - 1, n - 1);
    else
        return dp[m][n] = max(LCSMemo(x, y, m - 1, n), LCSMemo(x, y, m, n - 1));
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s1 = "aditya";
    string s2 = "adixxya";
    cout << LCSMemo(s1, s2, s1.size(), s2.size());
}