class Solution {
public:

    int fibo(int n, vector<int>& cost, vector<int>&dp){
       if(n - 1 < 0 || n - 2 < 0) return 0;
       if(dp[n]!=-1) return dp[n];
       return dp[n] = min(cost[n-1] + fibo(n-1,cost,dp) ,cost[n-2] + fibo(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(1001,-1);
        return fibo(cost.size(),cost, dp);
    }
};