class Solution {
public:
    
    int subsetXORSum(vector<int>& nums) {    
        return helper(0,0,nums);
    }

    int helper(int level , int currSum, vector<int>&nums){
          if(level>=nums.size()) return currSum;

          int taken = helper(level+1, currSum^nums[level], nums);
          int ntaken =  helper(level+1,currSum,nums);
          
          return taken + ntaken;
    }
};