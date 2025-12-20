class Solution {
public:
    int houseRobber(int n,vector<int>&dp, vector<int>&nums){
       if( n < 0) return 0; 
       if(dp[n]>-1) return dp[n]; 
       return dp[n] = max(houseRobber(n-1,dp, nums), nums[n] + houseRobber(n-2,dp,nums));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int>case1(nums.begin()+1, nums.end()), dp1(n,-1);
        vector<int>case2(nums.begin(), nums.begin()+n-1), dp2(n,-1);
        int l1 = case1.size();
        int l2 = case2.size();
        return max(houseRobber(l1-1,dp1, case1), houseRobber(l2-1,dp2, case2));
    }
};