class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        if(n == 1 || n == 0) return 1;
        if(dp[n]) return dp[n];
        return dp[n] =  climbStairs(n - 1) + climbStairs(n-2);
    }
};