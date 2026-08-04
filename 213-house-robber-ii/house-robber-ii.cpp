class Solution {
public:

    int houseRob(vector<int>& nums){
       int prev1 = nums[0];
        int prev2 = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1; 
    }

    int rob(vector<int>& nums) {
        vector<int>t1, t2;
        int n = nums.size();
        if(n == 1 ) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        return max(houseRob(t1),houseRob(t2));
    }
};