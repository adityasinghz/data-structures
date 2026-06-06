class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
         vector<vector<int>>res;
         for(int i = 0; i < n; i++){
             for(int j = i + 1; j < n; j++){
                int low = j + 1;
                int high = n - 1;
                long long int sum = target -  nums[i];
                sum-=nums[j];
                while( low < high){ 
                    if( nums[low] + nums[high] > sum){
                        high--;
                    }else if( nums[low] + nums[high] < sum){
                        low++;
                    }else{
                         res.push_back({nums[i], nums[j], nums[low], nums[high]});
                         int temp_low = low;
                         int temp_high = high;
                         while( low < high && nums[temp_low] == nums[low]) low++;
                         while( low < high && nums[temp_high] == nums[high]) high--;
                    }
                }
                int temp_j = j;
                while( j + 1 < n && nums[j + 1] == nums[temp_j]) j++;
             }
             int temp_i = i;
             while( i + 1 < n && nums[i + 1] == nums[temp_i]) i++;
         }
         return res;
    }
};