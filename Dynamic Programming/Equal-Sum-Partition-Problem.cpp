#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int arr[], int n, int sum)
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
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool EqualSumPartition(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);
    if (sum % 2 != 0)
        return 0;
    else if (sum % 2 == 0)
        return subsetsum(arr, n, sum / 2);
}

int main()
{
    int n = 4;
    int arr[n]{1, 5, 11, 5};
    cout << EqualSumPartition(arr, n);
}