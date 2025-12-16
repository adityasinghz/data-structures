class Solution {
public:
    vector<int>dp = vector<int>(10001,-1);
    int minCost(int n, vector<int>&cost){
        if(n - 1 < 0 || n - 2 < 0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = min(cost[n-1] + minCost(n-1, cost), cost[n-2] + minCost(n-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return minCost(n, cost);
    }
};