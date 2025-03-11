class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size()-1;
            while( low <high){
                if(nums[i] + nums[low] + nums[high] > 0)
                high--;
                else if(nums[i]+nums[low]+nums[high]<0)
                low++;
                else{
                   ans.push_back({nums[i],nums[low], nums[high]});
                   int temp_low = low;
                   int temp_high = high;
                   while(low<high&&nums[low]==nums[temp_low])low++;
                   while(low<high&&nums[high]==nums[temp_high])high--;
                }
            }
            int temp_i = i;
            while(i+1<nums.size()&&nums[temp_i]==nums[i+1])i++;
        }
        return ans;
    }
};