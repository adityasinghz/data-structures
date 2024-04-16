#include <bits/stdc++.h>
using namespace std;

int CountSubSetSumGivenDiff(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j > 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else if (arr[i - 1] <= sum)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[]{1, 1, 2, 3};
    int n = 4;
    int diff = 1;
    int sum = accumulate(arr, arr + n, 0);
    cout << CountSubSetSumGivenDiff(arr, n, (sum + diff) / 2);
}