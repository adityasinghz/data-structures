class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0;
        int high = 0;
        while(high < nums.size()){
         if(nums[high]!=0)
           swap(nums[low++], nums[high]);
        high++;
        }
    }
};