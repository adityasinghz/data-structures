class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSum;
        prefixSum[0]=1;
        int count = 0;
        int i = 0;
        int n  = nums.size();
        int sum = 0;
        while(i < n){
            sum+=nums[i++];

            int rem = sum - k;

                count+=prefixSum[rem];
            
            prefixSum[sum]++;
            
        }
        return count;
    }
};