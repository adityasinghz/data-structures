class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(target - nums[i])!=freq.end()) return {freq[target - nums[i]], i};
            freq[nums[i]] = i;
        }
        return {-1,-1};
    }
};