class Solution {
public:
    void knapSack(int n, int target, vector<int>& arr, vector<int>&current, vector<vector<int>>&result){
        if(target==0){
            result.push_back(current);
            return;
        }
        if(n==0 || target < 0) return;


        if(target >= arr[n-1]){
          current.push_back(arr[n-1]);
          knapSack(n, target-arr[n-1], arr, current, result);
          current.pop_back();
        }
        
        knapSack(n-1,target, arr, current, result);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       // sort(candidates.begin(), candidates.end()); 
        int n = candidates.size();
        vector<vector<int>>res;
        vector<int>curr;
        knapSack(n, target, candidates, curr, res);
        return res;
    }
};