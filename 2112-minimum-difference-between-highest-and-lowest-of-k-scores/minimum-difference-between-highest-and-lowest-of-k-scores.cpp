class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
         if(i+k-1 >=n) break;
         ans = min(ans, nums[i+k-1] - nums[i]);
        }
         
        return ans;
    }
};