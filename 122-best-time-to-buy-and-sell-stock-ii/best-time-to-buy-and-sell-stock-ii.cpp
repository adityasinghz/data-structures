class Solution {
public:
    int solve(int indx,vector<int>&prices, int buy, vector<vector<int>>&dp){
        long n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit = 0;
                if(j){
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                dp[i][j] = profit;
            }

        }
        return dp[0][1]; 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        return solve(0,prices,1, dp);
    }
};