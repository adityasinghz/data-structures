class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
             if(mp.count(nums[i]) && i- mp[nums[i]] <=k){
                   cout<<mp[nums[i]]<<' '<<i<<'\n';
                   return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};