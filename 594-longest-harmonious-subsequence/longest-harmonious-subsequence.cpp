class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  low = 0;
        int  high = 0;
        int  maxLen = 0;
        while(high < nums.size()){
            if(nums[high] - nums[low] == 1){
               maxLen = max(maxLen, high - low + 1);
            }else if(nums[high] - nums[low] > 1){
                while(nums[high] - nums[low] > 1){
                    low++;
                }
            }
            high++;
        }
        return maxLen;
    }
};