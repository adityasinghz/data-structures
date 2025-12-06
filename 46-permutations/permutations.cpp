class Solution {
public:
    void backtrack(vector<int>&ds,vector<int>&nums,unordered_map<int,bool>&freq,vector<vector<int>>&res){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[nums[i]]){
                freq[nums[i]] = true;
                ds.push_back(nums[i]);
                backtrack(ds,nums,freq,res);
                freq[nums[i]] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool>freq;
        vector<int>ds;
        vector<vector<int>>res;
        backtrack(ds,nums,freq,res);
        return res;
    }
};