class Solution {
public:
    int knapSack(int n, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(dp[n][target] != -1) return dp[n][target];
        if(target == 0) return 1;
        if(nums[n-1] <= target){
            dp[n][target] = knapSack(n-1, nums, target-nums[n-1], dp) || knapSack(n-1, nums, target, dp);
        }else{
            dp[n][target] = knapSack(n-1, nums, target, dp);
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(),0);
        if(target%2!=0) return false;
        target/=2;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        for(int i =1; i<=target; i++) dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i =0; i<=n;i++) dp[i][0] = 1;
        return knapSack(n, nums, target, dp);
    }
};