class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          vector<vector<int>>ans;
          int n = nums.size();
          for(int i=0;i<nums.size();i++){
              int low = i + 1;
              int high = nums.size() - 1;
              while(low < high){
                  int sum = nums[low] + nums[high] + nums[i];
                  if(sum > 0) high--;
                  else if(sum < 0) low++;
                  else{
                      ans.push_back({nums[i], nums[low], nums[high]});
                      int temp_l = low;
                      int temp_h = high;
                      while(low < high && nums[low]==nums[temp_l])low++;
                      while(low < high && nums[high]==nums[temp_h])high--; 
                  }   
              }
              int temp_i = i;
              while(i+1 < n && nums[i+1] == nums[temp_i])i++;
          }
          return ans;
    }
};