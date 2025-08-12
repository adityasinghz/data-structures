class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<=1) return nums[0];
        int i = 0;
        int j = 0;
        int len = 0;
        double sum = 0;
        double ans = INT_MIN;
        while(j < nums.size()){
            len++;
            sum+=nums[j++];
            if(len == k){
              ans =  max((double)sum/k, ans);
              sum-=nums[i++];
              len--;
            }
        }
        return ans;
    }
};