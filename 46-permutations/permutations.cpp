class Solution {
public:
    void fun(vector<int>&ds, unordered_map<int,int>freq, vector<int>&nums, vector<vector<int>>&ans){

        if(ds.size()==nums.size()){
          ans.push_back(ds);
          return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[nums[i]]){
                ds.push_back(nums[i]);
                freq[nums[i]]=true;
                fun(ds, freq, nums, ans);
                ds.pop_back();
                freq[nums[i]]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        unordered_map<int,int>freq;
        vector<vector<int>>ans;
        fun(ds,freq,nums,ans);
        return ans;
    }
};