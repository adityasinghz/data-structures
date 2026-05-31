class Solution {
public:
    int solve(int indx,vector<int>&prices, int buy, vector<vector<int>>&dp){
        int profit = 0;
        if(indx ==prices.size()) return 0;
        if(dp[indx][buy]!=-1) return dp[indx][buy];
        if(buy){
            profit+=max(-prices[indx] + solve(indx+1,prices,0,dp),solve(indx+1,prices,1,dp));
        }else{
            profit+=max( prices[indx] + solve(indx+1,prices,1,dp),solve(indx+1,prices,0,dp));
        }
        dp[indx][buy] = profit;
        return dp[indx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,1, dp);
    }
};