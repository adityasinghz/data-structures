class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            long long  target1=t-nums[i];
            for(int j = i+1; j<nums.size();j++){
                 long long target= target1-nums[j];
                 int low = j+1;
                 int high = nums.size()-1;
                 while(low < high){
                   if(  nums[low] + nums[high] > target){
                        high--;
                   }else if(  nums[low] + nums[high] < target){
                        low++;
                   }else{
                       res.push_back({nums[i], nums[j], nums[low], nums[high]});
                       int t1 = low;
                       int t2 = high;
                       while(low < high && nums[low] == nums[t1])low++;
                       while(low < high && nums[high]==nums[t2])high--;
                   }  
                 }
                 while(j+1 < nums.size() && nums[j]==nums[j+1]) j++;
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1]) i++; 
        }
        return res;
    }
};