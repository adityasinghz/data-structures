#include <bits/stdc++.h>
using namespace std;

int MinimumSubsetSumDifference(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);

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
    int res[n];
    int i = 0;
    for (int j = 0; j <= sum / 2; j++)
    {

        if (dp[n][j] == true)
            res[i++] = j;
    }
    int mini = INT_MAX;
    int size = sizeof(res) / sizeof(res[0]);
    for (int l = 0; l <= size; l++)
        mini = min(mini, sum - 2 * res[l]);

    return mini;
}
int main()
{
    int n = 4;
    int arr[]{1, 2, 7, 1};
    cout << MinimumSubsetSumDifference(arr, n);
}