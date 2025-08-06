class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 3 2 2 3
        // 2 2
        int j = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i]!=val) nums[j++] = nums[i];
        }
        return j;
    }
};