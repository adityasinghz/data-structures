class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1; 
        int ans = 1;

        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]) ++inc;
            else inc=1;
            
            if(nums[i] < nums[i+1]) ++dec;
            else dec=1;
            
            ans = max(ans, max(inc, dec));
             
        }
        return ans;
    }
};