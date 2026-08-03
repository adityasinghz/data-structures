class Solution {
public:
    int func(int n , vector<int>&nums,vector<int>&dp){
        if( n < 0) return 0;
        if(dp[n]!=-1) return dp[n]; 
        return dp[n] = max(func(n-1,nums,dp), nums[n] + func(n-2,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(101,-1);
        return func(n - 1 , nums, dp);
    }
};