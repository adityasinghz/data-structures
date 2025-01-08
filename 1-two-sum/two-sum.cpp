class Solution {
public:
  //test
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,string>mp;
         for(int i=0;i<nums.size();i++){
              if(mp[target - nums[i]].size()==0)
              mp[target - nums[i]] = to_string(i);
              if(mp[nums[i]].size()&&stoi(mp[nums[i]])!=i){
                  return {stoi(mp[nums[i]]), i};
              } 
          }
          return {-1,-1};
    }
};