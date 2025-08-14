class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = 1;
        int maxi = 0;
        while( j < nums.size()){
            if( nums[j] == 0)k--;
            if( k < 0){
               while(nums[i]==1)i++;
               if(nums[i]==0){i++;k++;}
            }
            maxi = max(maxi, j - i);
            j++;
        }
        return maxi;
    }
};