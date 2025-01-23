class Solution {
public:
    int LIS(int prev , int indx , vector<int>&nums, vector<vector<int>>&dp){
       if(indx == nums.size()) return 0;
       if(dp[indx][prev+1]!=-1) return dp[indx][prev+1];
       int len = LIS(prev, indx +1, nums,dp);
       if(prev==-1 || nums[indx] > nums[prev]){
         len = max(len,1+ LIS(indx, indx+1,nums,dp));
       }
       return dp[indx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Initialize DP table
    return LIS(-1, 0, nums, dp); // Start recursion
    }
};