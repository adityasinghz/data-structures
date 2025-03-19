class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        double sum = 0;
        double avg = 0;
        double ans = INT_MIN;
        while(high < nums.size()){
            sum+=nums[high];

            if(high - low + 1 == k){
                avg = sum/k;
                ans = max(ans, avg);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        return ans;
    }
};