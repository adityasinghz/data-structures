class Solution {
public:
    void backtrack(int n, int target, vector<int>&ds, vector<int>&arr, vector<vector<int>>&res){
    if(target==0){
       res.push_back(ds);
       return;
    }
    if(target < 0 || n == 0) return;
     
    if(arr[n-1]<=target){
        ds.push_back(arr[n-1]);
        backtrack(n,target-arr[n-1],ds,arr,res);
        ds.pop_back();
    }
    backtrack(n-1,target,ds,arr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>ds;
        vector<vector<int>>res;
        backtrack(arr.size(),target,ds,arr,res);
        return res;
    }
};