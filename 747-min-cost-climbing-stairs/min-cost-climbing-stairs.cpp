class Solution {
public:
    int dp[1001];
    int minCost(int n ,  vector<int>&cost){
        if( n - 2 < 0 || n - 1 < 0 ) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = min(cost[n-1] + minCost(n-1,cost), cost[n-2] + minCost(n-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return minCost(n, cost);
    }
};