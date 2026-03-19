class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n  = nums.size();
        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size() - 1;
            while(low < high){
                if(nums[low] + nums[high] + nums[i] > 0) high--;
                else if(nums[low] + nums[high] + nums[i] < 0) low++;
                else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    do{low++;} while(low+1 < n && nums[low]==nums[low-1]);
                    do{high--;} while(high-1 >=0 && nums[high]==nums[high+1]);
                }
            }
            while(i+1 < n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};