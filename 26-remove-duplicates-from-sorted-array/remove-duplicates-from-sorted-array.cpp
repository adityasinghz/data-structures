class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 1;
        int high = 1;
        int n = nums.size();

        while( low < n && high < n){
            if(nums[high]!=nums[high-1]){
                nums[low] = nums[high];
                low++;
            }
            high++;
        }
        return low;
    }
};