class Solution {
public:
    int houseRobber(int n, vector<int>&nums, vector<int>&dp){
        if(n < 0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max(houseRobber(n-1,nums,dp), nums[n] + houseRobber(n-2, nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return houseRobber(n-1,nums,dp);
    }
};