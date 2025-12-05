class Solution {
public:
void backtrack(int start, vector<int>&ds, vector<int>&nums, vector<vector<int>>&res){
  if(nums.size()==start) {res.push_back(ds); return;}
  if(start>=nums.size()) return;
  ds.push_back(nums[start]);
  backtrack(start+1,ds,nums,res);
  ds.pop_back();
  backtrack(start+1,ds,nums,res);
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>res;
        backtrack(0,ds,nums,res);
        return res;
}
};