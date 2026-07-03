class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        unordered_map<int,int>freq;
        freq[0] = 1;
        while( j < n){
            sum+=nums[j]%2;
            if( freq.count(sum - k) > 0 ){
               ans+=freq[sum-k];
            }
          freq[sum]++;
          j++;
        } 
        return ans;
    }
};