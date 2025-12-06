class Solution {
public:
    void backtrack(int start, int target, vector<int>&ds, vector<int>nums, vector<vector<int>>&res){
       if(target==0){
          res.push_back(ds);
          return;
       }
       if(target<0) return;

       for(int i=start;i<nums.size();i++){
          if(i>start && nums[i]==nums[i-1]) continue;
          ds.push_back(nums[i]);
          backtrack(i+1,target-nums[i],ds,nums,res);
          ds.pop_back();
       }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>res;
        backtrack(0,target,ds,nums,res);
        return res;
    }
};