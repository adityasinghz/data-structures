class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int mul = 1;
        int countZero = 0;
        for(auto num : nums){
          if(num==0) countZero++;
          else mul*=num;
        }
        vector<int>ans(nums.size(), mul);
        for(int i =0 ; i<ans.size();i++){
          if(nums[i]==0 && countZero>1 || nums[i]!=0 && countZero) ans[i] = 0;
          else if(nums[i]!=0) ans[i]/=nums[i];
        }

        return ans; 
    }
};