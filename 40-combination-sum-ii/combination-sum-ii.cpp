class Solution {
public:
    void knapSack(int n, int target, vector<int>&arr, vector<int>&current, vector<vector<int>>&result){
        if(target == 0){
          result.push_back(current);
          return;
        }
        if(n <= 0 || target < 0) return;

        if(target >= arr[n-1]){
           current.push_back(arr[n-1]);
           knapSack(n-1, target-arr[n-1], arr, current, result);
           current.pop_back();    
        }
        while(n-1>=0 && n-2>=0 &&  arr[n-1]==arr[n-2])n--;
        
        knapSack(n-1, target, arr, current, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>current;
        vector<vector<int>>result;
        int n = arr.size();
        knapSack(n, target, arr, current, result);
        return result;
    }
};