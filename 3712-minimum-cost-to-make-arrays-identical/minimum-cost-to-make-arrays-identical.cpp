class Solution {
public:
    long long withoutK(vector<int>&arr, vector<int>&brr){
         long long diff = 0;
         for(int i=0;i<arr.size();i++){
             diff+=abs(arr[i] - brr[i]);
         }
         return diff;
    }
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long int withoutKSum = withoutK(arr,brr);
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long int sum  = withoutK(arr,brr);
        return min(sum + k, withoutKSum);
    }
};