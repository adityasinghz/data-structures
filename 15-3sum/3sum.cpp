class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int low = i+1;
            int high = n - 1;
            while(low < high){
                if( nums[i] + nums[low] + nums[high] > 0) high--;
                else if( nums[i] + nums[low] + nums[high] < 0) low++;
                else{
                   res.push_back({nums[i], nums[low], nums[high]});
                   int temp_low = nums[low];
                   int temp_high = nums[high];
                   do{low++;}while(low < high && temp_low == nums[low]);
                   do{high--;}while(low < high && temp_high==nums[high]);
                }
            }
            int temp_i = nums[i];
            while(i + 1 < n && temp_i == nums[i+1]) i++;
        }
        return res;
    }
};