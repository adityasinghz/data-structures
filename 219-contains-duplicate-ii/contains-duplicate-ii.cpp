class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        for(int i = 0;i<nums.size();i++){
            if(freq.find(nums[i]) != freq.end()){
              if(abs(freq[nums[i]] - i)<=k) return true;
            }
            freq[nums[i]] = i;
        }
        return false;
    }
};


// 1, 2, 3, 1, 2, 3
// 0  1  2  3  4  5

