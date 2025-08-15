class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int prefix = 0;
        for(int i=0;i<nums.size();i++){
            int suffix = sum - nums[i] - prefix;
            if(prefix==suffix) return i;
            prefix+=nums[i];
        }
        return -1;
    }
};