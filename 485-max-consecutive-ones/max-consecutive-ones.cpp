class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0;
        int ans = 0;
        int ct = 0;
        while(j < nums.size()){
            if(nums[j]!=1) ct =0;
            else ct++;
            ans = max(ans,ct);
            j++; 
        }
        return ans;
    }
};