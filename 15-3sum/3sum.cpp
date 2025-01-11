class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size()-1;
            while(high>low){
             if(nums[i] + nums[low] + nums[high] > 0){
                high--;
             }else if(nums[i] + nums[low] + nums[high] < 0){
                low++;
             }else{
                res.push_back({nums[low],nums[i],nums[high]});
                int t1= low, t2 = high;
                while(low<high && nums[t2]==nums[low]){ 
                  low++;
                }
                while(low<high && nums[t2]==nums[high]){
                    high--;
                }
             }
            }
            while(i+1<nums.size()&& nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};