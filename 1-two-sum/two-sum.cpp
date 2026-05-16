class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>freq;

       for(int i=0;i<nums.size();i++){
         int tar = target-nums[i];
         if(freq.find(tar)!=freq.end()) return {i, freq[tar]};
         freq[nums[i]] = i;
       }
       return {-1,-1};
    }
};