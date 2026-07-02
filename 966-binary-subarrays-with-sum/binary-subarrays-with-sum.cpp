class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int>freq;
        freq[0] = 1;
        int ans = 0;
        while( j < n ){
            sum+=nums[j];
            if(freq.count(sum - goal) > 0) ans+=freq[sum - goal];
            freq[sum]++;
            j++;
        }
        return ans;
    }
};