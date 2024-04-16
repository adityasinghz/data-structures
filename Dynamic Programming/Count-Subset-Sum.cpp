#include <bits/stdc++.h>
using namespace std;

int CountOfSubsetSum(int arr[], int n, int Sum)
{
    int dp[n + 1][Sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= Sum; j++)
        {
            if (i == 0 && j > 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][Sum];
}
int main()
{
    int arr[6]{2, 3, 5, 6, 8, 10};
    int Sum = 10;
    cout << CountOfSubsetSum(arr, 6, Sum);
}