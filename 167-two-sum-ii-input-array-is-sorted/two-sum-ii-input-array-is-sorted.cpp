class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low < high){
            int total = nums[low] + nums[high];

            if(total==target) return {low+1, high+1};

            else if(total > target) high--;

            else low++;
        }
        return {-1,-1};
    }
    // [2, 7, 8, 10, 11, 12, 13, 14, 15]
};