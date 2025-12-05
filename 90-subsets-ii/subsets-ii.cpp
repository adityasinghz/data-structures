class Solution {
public:
    void backtrack(int start, vector<int>&ds, vector<int>&nums,vector<vector<int>>&res){
        res.push_back(ds);
        for(int i=start;i<nums.size();i++){
           if(i > start && nums[i]==nums[i-1]) continue;
           ds.push_back(nums[i]);
           backtrack(i+1,ds,nums,res);
           ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        backtrack(0,ds,nums,res);
        return res;        
    }
};