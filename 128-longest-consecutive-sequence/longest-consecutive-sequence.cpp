class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int ct=1;
        int maxi = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i])continue;
            else if(nums[i+1]-nums[i]==1)ct++;
            else ct=1;
            maxi = max(maxi, ct);
        }
        return maxi;
    }
};