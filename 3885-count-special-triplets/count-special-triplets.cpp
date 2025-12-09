class Solution {
public:
    int const MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>suffix;
        unordered_map<int,int>prefix;
        long long int ans = 0;
        for(int i=0;i<nums.size();i++){
            suffix[nums[i]]++;
        }
        for(int j=0;j<nums.size();j++){
            suffix[nums[j]]--;
            ans+=((long long)prefix[nums[j]*2]*suffix[nums[j]*2]);
            prefix[nums[j]]++;
        }
        return ans%MOD;
    }
};