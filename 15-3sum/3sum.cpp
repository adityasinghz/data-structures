class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
             int j = i+1;
             int k = nums.size()-1;
             while( j < k){
                 if(nums[i] + nums[j] + nums[k] > 0)k--;
                 else if(nums[i]+nums[j] + nums[k] < 0)j++;
                 else{ 
                    res.push_back({nums[i],nums[j],nums[k]}); 
                    int temp_j = j;
                    int temp_k = k;
                    while(j < k && nums[temp_j]==nums[j])j++;
                    while(j < k && nums[temp_k]==nums[k])k--;
                 }
             }
             int temp_i = i;
             while(i+1 < nums.size() && nums[temp_i]==nums[i+1])i++;
        }
        return res;
    }
};