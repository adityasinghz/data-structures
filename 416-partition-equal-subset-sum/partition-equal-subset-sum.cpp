class Solution {
public:
    bool knapSack(int n, vector<int>&wt, int W, vector<vector<int>>&dp){
        if(dp[n][W]!=-1) return dp[n][W];

        if(W==0) return true;

        if(wt[n-1]<=W)
         dp[n][W] = knapSack(n-1, wt , W - wt[n-1], dp) || knapSack(n-1,wt, W, dp);
        else
         dp[n][W] = knapSack(n-1, wt, W, dp);

        return dp[n][W];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int W = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
        if(sum%2 != 0) return false;
        for(int i=0;i<=W;i++){
            dp[0][i] = false;
        }
        for(int i = 0;i<=n;i++){
           dp[i][0]=true;
        }
        
        knapSack(n , nums, W , dp);

        return dp[n][W];
    }
};