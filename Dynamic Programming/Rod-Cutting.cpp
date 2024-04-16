#include <bits/stdc++.h>
using namespace std;

int rodcutting(int wt[], int val[], int length)
{
    int dp[length + 1][length + 1];
    for (int i = 0; i <= length; i++)
    {
        for (int j = 0; j <= length; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[length][length];
}

int main()
{
    int length;
    cin >> length;
    int wt[length];
    int val[length]{1, 5, 8, 9, 10, 17, 17, 20};
    for (int i = 1; i <= length; i++)
        wt[i - 1] = i;
    cout << rodcutting(wt, val, length);
}