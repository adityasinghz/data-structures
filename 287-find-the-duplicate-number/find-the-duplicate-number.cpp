class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            int n = abs(nums[i]);
            if( nums[n] < 0 )
                return n;
            nums[n] *= -1;
        }
        return -1;
    }
};