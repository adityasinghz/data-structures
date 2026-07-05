class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++) ans+=nums[i];
        
        int curr = ans;

        for(int i = k - 1; i >=0; i--){
            curr-=nums[i];
            curr+=nums[n - k + i];

            ans = max(ans, curr);
        }
        return ans;
    }
};