class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int len = 1;
        int ans = 1;
        int sum = nums[0];
        int res = sum;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                len++;
                sum+=nums[i];
            }else{ 
                len = 1;
                sum = nums[i];
            }
            if(res < sum){
                ans = len;
                res = sum;
            }
        }
        return res;
    }
};